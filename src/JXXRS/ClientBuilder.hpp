//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_ClientBuilder_INCLUDED
#define JXXRS_ClientBuilder_INCLUDED

#include "JXXRS/Client.hpp"
#include "JXXRS/SSLProtocol.hpp"
#include <memory>
#include <string>

namespace JXXRS {

struct AbstractClientBuilder;

struct ClientBuilder
{
	ClientBuilder();
	
	ClientBuilder& connectionPoolSize(std::size_t size);
	ClientBuilder& httpProxy(const std::string& uri);
	ClientBuilder& noProxy(std::string& pattern);
	ClientBuilder& sslProtocol(SSLProtocol protocol);
	ClientBuilder& sslCiphers(const std::string& cipherList);
	ClientBuilder& sslVerify(bool verify);
	ClientBuilder& sslVerificationDepth(int depth);
	ClientBuilder& sslTrustStore(const std::string& pemFile);
	ClientBuilder& sslDefaultCAs(bool useDefaultCAs);
	ClientBuilder& sslKeyStore(const std::string& pkcs12File, const std::string& password);
	std::shared_ptr<Client> build();

private:

	std::unique_ptr<AbstractClientBuilder> pimpl;
};

} // namespace JXXRS

#endif // JXXRS_ClientBuilder_INCLUDED
