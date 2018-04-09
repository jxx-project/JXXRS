//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/ClientBuilder.h"
#include "JXXRS/Error.h"
#include "JXXRS/PocoImpl/BasicConnectionFactory.h"
#include "JXXRS/PocoImpl/Client.h"
#include <Poco/Crypto/PKCS12Container.h>
#include <Poco/Crypto/RSAKey.h>

namespace JXXRS { namespace PocoImpl {

ClientBuilder::ClientBuilder() :
		connectionFactory(nullptr),
		httpProxy(""),
		httpNoProxy(""),
		tlsUsage(Poco::Net::Context::Usage::TLSV1_2_CLIENT_USE),
		tlsCiphers("ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH"),
		tlsVerify(true),
		tlsVerificationDepth(9),
		tlsTrustStore(""),
		tlsUseDefaultCAs(false),
		tlsKeyStore(""),
		tlsKeyPassword(""),
		configuration(nullptr)
{
}

void ClientBuilder::property(const std::string& name, std::shared_ptr<JXXRS::Configuration::Object>&& value)
{
	if (name == "connectionFactory") {
		connectionFactory = std::dynamic_pointer_cast<JXXRS::ConnectionFactory>(value);
	} else {
		throw JXXRS::Error("JXXRS::PocoImpl::ClientBuilder: Unknown JXXRS::Configuration::Object property " + name);
	}
	configuration = nullptr;
}

void ClientBuilder::property(const std::string& name, const std::string& value)
{
	if (name == "HTTP::proxy") {
		httpProxy = Poco::URI(value);
	} else if (name == "HTTP::noProxy") {
		httpNoProxy = value;
	} else if (name == "TLS::protocol") {
		if (value == "TLSv1") {
			tlsUsage = Poco::Net::Context::Usage::TLSV1_CLIENT_USE;
		} else if (value == "TLSv1.1") {
			tlsUsage = Poco::Net::Context::Usage::TLSV1_1_CLIENT_USE;
		} else if (value == "TLSv1.2") {
			tlsUsage = Poco::Net::Context::Usage::TLSV1_2_CLIENT_USE;
		} else {
			throw JXXRS::Error("JXXRS::PocoImpl::ClientBuilder: Unknown TLS::protocol " + value);
		}
	} else if (name == "TLS::ciphers") {
		tlsCiphers = value;
	} else if (name == "TLS::trustStore") {
		tlsTrustStore = value;
	} else if (name == "TLS::keyStore") {
		tlsKeyStore = value;
	} else if (name == "TLS:keyPassword") {
		tlsKeyPassword = value;
	} else {
		throw JXXRS::Error("JXXRS::PocoImpl::ClientBuilder: Unknown std::string property " + name);
	}
	configuration = nullptr;
}

void ClientBuilder::property(const std::string& name, int value)
{
	if (name == "TLS::verificationDepth") {
		tlsVerificationDepth = value;
	} else if (name == "TLS::verificationDepth") {
		tlsVerificationDepth = value;
	} else {
		throw JXXRS::Error("JXXRS::PocoImpl::ClientBuilder: Unknown bool property " + name);
	}
	configuration = nullptr;
}

void ClientBuilder::property(const std::string& name, bool value)
{
	if (name == "TLS::verify") {
		tlsVerify = value;
	} else if (name == "TLS::useDefaultCAs") {
		tlsUseDefaultCAs = value;
	} else {
		throw JXXRS::Error("JXXRS::PocoImpl::ClientBuilder: Unknown bool property " + name);
	}
	configuration = nullptr;
}

std::shared_ptr<JXXRS::Client> ClientBuilder::build()
{
	if (!connectionFactory) {
		connectionFactory = std::make_shared<BasicConnectionFactory>();
	}
	if (!configuration) {
		configuration = std::make_shared<Configuration>(connectionFactory, createSSLContext(), createProxyConfig());
	}
	return std::make_shared<JXXRS::PocoImpl::Client>(configuration);
}

Poco::Net::Context::Ptr ClientBuilder::createSSLContext() const
{
	Poco::Net::Context::Ptr context(
		new Poco::Net::Context(
			tlsUsage,
			tlsTrustStore,
			(tlsVerify ?
			 Poco::Net::Context::VerificationMode::VERIFY_RELAXED :
			 Poco::Net::Context::VerificationMode::VERIFY_NONE),
			tlsVerificationDepth,
			tlsUseDefaultCAs,
			tlsCiphers));
	if (!tlsKeyStore.empty()) {
		Poco::Crypto::PKCS12Container pkcs12Container(tlsKeyStore, tlsKeyPassword);
		context->useCertificate(pkcs12Container.getX509Certificate());
		context->usePrivateKey(Poco::Crypto::RSAKey(pkcs12Container.getKey()));
	}
	return context;
}

Poco::Net::HTTPClientSession::ProxyConfig ClientBuilder::createProxyConfig() const
{
	Poco::Net::HTTPClientSession::ProxyConfig config;
	if (!httpProxy.empty()) {
		config.host = httpProxy.getHost();
		config.port = httpProxy.getPort();
		auto userInfo = httpProxy.getUserInfo();
		if (!userInfo.empty()) {
			auto separator = userInfo.find(':');
			if (separator == std::string::npos) {
				throw Error("Malformed user info in proxy URI");
			}
			config.username = userInfo.substr(0, separator);
			config.password = userInfo.substr(separator + 1, std::string::npos);
		}
		config.nonProxyHosts = httpNoProxy;
	}
	return config;
}

}} // namespace JXXRS::PocoImpl
