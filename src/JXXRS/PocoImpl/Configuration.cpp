//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/Configuration.h"
#include "JXXRS/PocoImpl/BasicConnectionFactory.h"
#include "JXXRS/PocoImpl/PoolingConnectionFactory.h"
#include "JXXRS/PocoImpl/Client.h"
#include <Poco/Crypto/PKCS12Container.h>
#include <Poco/Crypto/RSAKey.h>

namespace JXXRS { namespace PocoImpl {

Configuration::Configuration(
	std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory,
	Poco::Net::Context::Ptr sslContext,
	Poco::Net::HTTPClientSession::ProxyConfig proxyConfig) :
		connectionFactory(connectionFactory),
		sslContext(sslContext),
		proxyConfig(proxyConfig)
{
}

Configuration::~Configuration()
{
}

JXXRS::ConnectionFactory& Configuration::getConnectionFactory()
{
	return *connectionFactory;
}

Poco::Net::Context::Ptr Configuration::getSSLContext()
{
	return sslContext;
}

const Poco::Net::HTTPClientSession::ProxyConfig& Configuration::getProxyConfig() const
{
	return proxyConfig;
}

}} // namespace JXXRS::PocoImpl
