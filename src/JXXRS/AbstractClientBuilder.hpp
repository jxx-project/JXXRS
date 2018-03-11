//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_AbstractClientBuilder_INCLUDED
#define JXXRS_AbstractClientBuilder_INCLUDED

#include "JXXRS/Client.hpp"
#include "JXXRS/SSLProtocol.hpp"
#include <memory>
#include <string>

namespace JXXRS {

struct AbstractClientBuilderImpl;

struct AbstractClientBuilder
{
	virtual ~AbstractClientBuilder()
	{
	}
	
	virtual void connectionPoolSize(std::size_t size) = 0;
	virtual void httpProxy(const std::string& uri) = 0;
	virtual void noProxy(std::string& pattern) = 0;
	virtual void sslProtocol(SSLProtocol protocol) = 0;
	virtual void sslCiphers(const std::string& cipherList) = 0;
	virtual void sslVerify(bool verify) = 0;
	virtual void sslVerificationDepth(int depth) = 0;
	virtual void sslTrustStore(const std::string& pemFile) = 0;
	virtual void sslDefaultCAs(bool useDefaultCAs) = 0;
	virtual void sslKeyStore(const std::string& pkcs12File, const std::string& password) = 0;
	virtual std::shared_ptr<Client> build() = 0;
};

} // namespace JXXRS

#endif // JXXRS_AbstractClientBuilder_INCLUDED
