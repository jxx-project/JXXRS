//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_AbstractConfiguration_INCLUDED
#define JXXRS_PocoImpl_AbstractConfiguration_INCLUDED

#include "JXXRS/Configuration.h"
#include "JXXRS/ConnectionFactory.h"
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPClientSession.h>
#include <memory>

namespace JXXRS { namespace PocoImpl {

class Configuration : public JXXRS::Configuration
{
public:
	Configuration(
		std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory,
		Poco::Net::Context::Ptr sslContext,
		Poco::Net::HTTPClientSession::ProxyConfig proxyConfig);
	virtual ~Configuration();

	JXXRS::ConnectionFactory& getConnectionFactory();
	Poco::Net::Context::Ptr getSSLContext();
	const Poco::Net::HTTPClientSession::ProxyConfig& getProxyConfig() const;

private:
	std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory;
	Poco::Net::Context::Ptr sslContext;
	Poco::Net::HTTPClientSession::ProxyConfig proxyConfig;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_Configuration_INCLUDED
