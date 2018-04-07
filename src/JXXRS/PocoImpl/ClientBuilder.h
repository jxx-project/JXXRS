//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_AbstractClientBuilder_INCLUDED
#define JXXRS_PocoImpl_AbstractClientBuilder_INCLUDED

#include "JXXRS/AbstractClientBuilder.h"
#include "JXXRS/Client.h"
#include "JXXRS/ConnectionFactory.h"
#include "JXXRS/PocoImpl/Configuration.h"
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/URI.h>

namespace JXXRS { namespace PocoImpl {

class ClientBuilder : public AbstractClientBuilder
{
public:
	ClientBuilder();
	virtual ~ClientBuilder();

	virtual void property(const std::string& name, std::shared_ptr<JXXRS::Configuration::Object>&& value);
	virtual void property(const std::string& name, const std::string& value);
	virtual void property(const std::string& name, int value);
	virtual void property(const std::string& name, bool value);
	virtual std::unique_ptr<JXXRS::Client> newClient();

private:
	Poco::Net::Context::Ptr createSSLContext() const;
	Poco::Net::HTTPClientSession::ProxyConfig createProxyConfig() const;

	std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory;
	Poco::URI httpProxy;
	std::string httpNoProxy;
	Poco::Net::Context::Usage tlsUsage;
	std::string tlsCiphers;
	bool tlsVerify;
	int tlsVerificationDepth;
	std::string tlsTrustStore;
	bool tlsUseDefaultCAs;
	std::string tlsKeyStore;
	std::string tlsKeyPassword;
	std::shared_ptr<Configuration> configuration;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_ClientBuilder_INCLUDED
