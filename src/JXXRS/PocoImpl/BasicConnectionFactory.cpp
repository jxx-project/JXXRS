//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/BasicConnectionFactory.hpp"
#include "JXXRS/PocoImpl/Connection.hpp"
#include "JXXRS/PocoImpl/Session.hpp"
#include <iostream>

namespace JXXRS {
namespace PocoImpl {

BasicConnectionFactory::BasicConnectionFactory(
	Poco::Net::Context::Ptr sslContext,
	Poco::Net::HTTPClientSession::ProxyConfig& proxyConfig) :
		sslContext(sslContext), proxyConfig(proxyConfig)
{
}

BasicConnectionFactory::~BasicConnectionFactory() {
}

std::unique_ptr<JXXRS::Connection> BasicConnectionFactory::get(
	const std::string& scheme,
	const std::string& host,
	std::uint16_t port)
{
	return std::unique_ptr<Connection>(
		new Connection(
			std::shared_ptr<Session>(
				new Session(
					scheme,
					host,
					port,
					false,
					sslContext,
					proxyConfig))));
}

} // namespace PocoImpl
} // namespace JXXRS
