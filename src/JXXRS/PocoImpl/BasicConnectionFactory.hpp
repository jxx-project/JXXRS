//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_BasicConnectionFactory_INCLUDED
#define JXXRS_PocoImpl_BasicConnectionFactory_INCLUDED

#include "JXXRS/ConnectionFactory.hpp"
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPClientSession.h>

namespace JXXRS {
namespace PocoImpl {

struct BasicConnectionFactory : public JXXRS::ConnectionFactory
{
	BasicConnectionFactory(Poco::Net::Context::Ptr sslContext,
						   Poco::Net::HTTPClientSession::ProxyConfig& proxyConfig);
	virtual ~BasicConnectionFactory();

	virtual std::unique_ptr<JXXRS::Connection> get(
		const std::string& scheme,
		const std::string& host,
		std::uint16_t port) override;

private:

	Poco::Net::Context::Ptr sslContext;
	Poco::Net::HTTPClientSession::ProxyConfig proxyConfig;
};

} // namespace PocoImpl
} // namespace JXXRS

#endif // JXXRS_PocoImpl_BasicConnectionFactory_INCLUDED
