//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/PocoImpl/Session.h"
#include "JXXRS/PocoImpl/HTTPClientSessionFactory.h"
#include <stdexcept>

namespace JXXRS { namespace PocoImpl {

Session::Session(
	const std::string& scheme,
	const std::string& host,
	std::uint16_t port,
	bool keepAlive,
	const Poco::Net::Context::Ptr sslContext,
	const Poco::Net::HTTPClientSession::ProxyConfig& proxyConfig,
	const HTTPClientSessionFactory& httpClientSessionFactory) :
	acquired(false),
	releasedAt(std::chrono::high_resolution_clock::now()),
	keepAlive(keepAlive),
	httpClientSession(httpClientSessionFactory.get(scheme, host, port, sslContext))
{
	httpClientSession->setKeepAlive(keepAlive);
	httpClientSession->setProxyConfig(proxyConfig);
}

Session::~Session()
{
}

void Session::acquire()
{
	if (acquired) {
		throw std::logic_error("JXXRS::PocoImpl::Session::acquire: Already acquired! ");
	} else {
		acquired = true;
	}
}

void Session::release()
{
	if (acquired) {
		if (!keepAlive) {
			httpClientSession->socket().close();
		}
		acquired = false;
	} else {
		throw std::logic_error("JXXRS::PocoImpl::Session::release: Not acquired! ");
	}
}

bool Session::inUse() const
{
	return acquired;
}

bool Session::releasedAfter(const Session& other) const
{
	return releasedAt > other.releasedAt;
}

}} // namespace JXXRS::PocoImpl
