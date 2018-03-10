//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_AbstractClientBuilder_INCLUDED
#define JXXRS_PocoImpl_AbstractClientBuilder_INCLUDED

#include "JXXRS/AbstractClientBuilder.hpp"
#include "JXXRS/Client.hpp"
#include "JXXRS/SSLProtocol.hpp"
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPClientSession.h>

namespace JXXRS {
namespace PocoImpl {

struct ClientBuilder : public AbstractClientBuilder
{
	virtual ~ClientBuilder();
	
	virtual void connectionPoolSize(std::size_t size) override;
	virtual void httpProxy(const std::string& uri) override;
	virtual void noProxy(std::string& pattern) override;
	virtual void sslProtocol(JXXRS::SSLProtocol protocol) override;
	virtual void sslCiphers(const std::string& cipherList) override;
	virtual void sslVerify(bool verify) override;
	virtual void sslVerificationDepth(int depth) override;
	virtual void sslTrustStore(const std::string& pemFile) override;
	virtual void sslDefaultCAs(bool useDefaultCAs) override;
	virtual void sslKeyStore(const std::string& pkcs12File, const std::string& password) override;
	virtual std::shared_ptr<JXXRS::Client> build() override;

private:

	Poco::Net::Context::Ptr createSSLContext() const;
	Poco::Net::HTTPClientSession::ProxyConfig createProxyConfig() const;
	
	std::size_t        clientConnectionPoolSize;
	std::string        httpProxyURI;
	std::string        noProxyPattern;
	JXXRS::SSLProtocol clientSSLProtocol;
	std::string        clientSSLCiphers;
	bool               clientSSLVerify;
	int                clientSSLVerificationDepth;
	std::string        clientSSLTrustStore;
	bool               clientSSLDefaultCAs;
	std::string        clientSSLKeyStore;
	std::string        clientSSLKeyPassword;
};

} // namespace PocoImpl
} // namespace JXXRS

#endif // JXXRS_PocoImpl_ClientBuilder_INCLUDED
