//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/HTTPClientSessionFactory.h"
#include "JXXRS/Error.h"
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPSClientSession.h>

namespace JXXRS { namespace PocoImpl {

HTTPClientSessionFactory::HTTPClientSessionFactory()
{
}

HTTPClientSessionFactory::~HTTPClientSessionFactory()
{
}

std::unique_ptr<Poco::Net::HTTPClientSession> HTTPClientSessionFactory::get(
	const std::string& scheme,
	const std::string& host,
	std::uint16_t port,
	const Poco::Net::Context::Ptr sslContext) const
{
	if (scheme == "http") {
		return std::unique_ptr<Poco::Net::HTTPClientSession>(new Poco::Net::HTTPClientSession(host, port));
	} else if (scheme == "https") {
		return std::unique_ptr<Poco::Net::HTTPClientSession>(new Poco::Net::HTTPSClientSession(host, port, sslContext));
	} else {
		throw JXXRS::Error("JXXRS::PocoImpl::HTTPClientSessionFactory::get: Unknown scheme \"" + scheme + "\"");
	}
}

}} // namespace JXXRS::PocoImpl
