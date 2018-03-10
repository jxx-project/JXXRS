//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/ClientBuilder.hpp"
#include "JXXRS/PocoImpl/BasicConnectionFactory.hpp"
#include "JXXRS/PocoImpl/PoolingConnectionFactory.hpp"
#include "JXXRS/PocoImpl/Client.hpp"
#include <Poco/Crypto/PKCS12Container.h>
#include <Poco/Crypto/RSAKey.h>

namespace JXXRS {
namespace PocoImpl {

ClientBuilder::ClientBuilder() :
		clientConnectionPoolSize(0),
		httpProxyURI(""),
		noProxyPattern(""),
		clientSSLProtocol(ClientBuilder::TLSV1_2),
		clientSSLCiphers(""),
		clientSSLVerify(true),
		clientSSLVerificationDepth(9),
		clientSSLTrustStore(""),
		clientSSLDefaultCAs(false),
		clientSSLKeyStore(""),
		clientSSLKeyPassword("")
{
}

void ClientBuilder::connectionPoolSize(std::size_t size)
{
	clientConnectionPoolSize = size;
}
	
void ClientBuilder::httpProxy(const std::string& uri)
{
	httpProxyURI = uri;
}
	
void ClientBuilder::noProxy(std::string& pattern)
{
	noProxyPattern = pattern;
}
	
void ClientBuilder::sslProtocol(Protocol protocol)
{
	clientSSLProtocol = protocol;
}
	
void ClientBuilder::sslCiphers(const std::string& cipherList)
{
	clientSSLCiphers = cipherList;
}
	
void ClientBuilder::sslVerify(bool verify)
{
	clientSSLVerify = verify;
}
	
void ClientBuilder::sslVerificationDepth(int depth)
{
	clientSSLVerificationDepth = depth;
}
	
void ClientBuilder::sslTrustStore(const std::string& pemFile)
{
	clientSSLTrustStore = pemFile;
}
	
void ClientBuilder::sslDefaultCAs(bool useDefaultCAs)
{
	clientSSLDefaultCAs = useDefaultCAs;
}
	
void ClientBuilder::sslKeyStore(const std::string& pkcs12File, const std::string& password)
{
	clientSSLKeyStore = pkcs12File;
	clientSSLKeyPassword = password;
}

std::shared_ptr<Client> ClientBuilder::build()
{
	Poco::Net::HTTPClientSession::ProxyConfig proxyConfig;
	
									 
	std::shared_ptr<ConnectionFactory> connectionFactory;
	if (clientConnectionPoolSize) {
		sslContext->enableSessionCache(true);
		connectionFactory = std::shared_ptr<JXXRS::PocoImpl::PoolingConnectionFactory>(
			new JXXRS::PocoImpl::PoolingConnectionFactory(
				createSSLContext(), createProxyConfig(), clientConnectionPoolSize, true));
	} else {
		sslContext->disableStatelessSessionResumption();
		connectionFactory = std::shared_ptr<JXXRS::PocoImpl::BasicConnectionFactory>(
			new JXXRS::PocoImpl::BasicConnectionFactory(
				createSSLContext(), createProxyConfig()));
	}
	return std::shared_ptr<JXXRS::PocoImpl::Client>(new JXXRS::PocoImpl::Client(connectionFactory));
}
	
Poco::Net::Context::Ptr ClientBuilder::createSSLContext() const
{
	Poco::Net::Context::Usage usage;
	switch (clientSSLProtocol) {
	case JXXRS::SSLProtocol::TLSV1:
		usage = Poco::Net::Context::Usage::TLSV1_CLIENT_USE;
		break;
	case JXXRS::SSLProtocol::TLSV1_1:
		usage = Poco::Net::Context::Usage::TLSV1_1_CLIENT_USE;
		break;
	case JXXRS::SSLProtocol::TLSV1_2:
		usage = Poco::Net::Context::Usage::TLSV1_2_CLIENT_USE;
		break;
	default:
		usage = Poco::Net::Context::Usage::TLSV1_2_CLIENT_USE;
	}
	Poco::Net::Context::Ptr context(
		new Poco::Net::Context(
			usage,
			clientSSLTrustStore,
			(clientSSLVerify ?
			 Poco::Net::Context::VerificationMode::VERIFY_RELAXED :
			 Poco::Net::Context::VerificationMode::VERIFY_NONE),
			clientSSLVerificationDepth,
			clientSSLDefaultCAs,
			clientSSLCiphers));
	if (!clientSSLKeyStore.empty()) {
		Poco::Crypto::PKCS12Container pkcs12Container(clientSSLKeyStore, clientSSLKeyPassword);
		context->useCertificate(pkcs12Container.getX509Certificate());
		context->usePrivateKey(Poco::Crypto::RSAKey(pkcs12Container.getKey()));
	}
	return context;
}

Poco::Net::HTTPClientSession::ProxyConfig ClientBuilder::createProxyConfig()
{
	ProxyConfig config;
	if (!httpProxyURI.empty) {
		config.host = httpProxyURI.getHost();
		config.port = httpProxyURI.getPort();
		auto userInfo = httpProxyURI.getUserInfo();
		if (!userInfo.empty()) {
			auto separator = userInfo.find(':');
			if (separator == string::npos) {
				throw Error("Malformed user info in proxy URI");
			}
			config.username = userInfo.substr(0, separator);
			config.password = userInfo.substr(separator + 1, string::npos);
		}
		config.nonProxyHosts = noProxyPattern;
	}
	return config;
}

} // namespace PocoImpl
} // namespace JXXRS
