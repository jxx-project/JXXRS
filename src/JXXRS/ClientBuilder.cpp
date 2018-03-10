//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/ClientBuilder.hpp"
#include "JXXRS/PocoImpl/ClientBuilder.hpp"

namespace JXXRS {

ClientBuilder::ClientBuilder() : pimpl(new PocoImpl::ClientBuilder())
{
}

ClientBuilder& ClientBuilder::connectionPoolSize(std::size_t size)
{
	pimpl->connectionPoolSize(size);
	return *this;
}
	
ClientBuilder& ClientBuilder::httpProxy(const std::string& uri)
{
	pimpl->httpProxy(uri);
	return *this;
}
	
ClientBuilder& ClientBuilder::noProxy(std::string& pattern)
{
	pimpl->noProxy(pattern);
	return *this;
}
	
ClientBuilder& ClientBuilder::sslProtocol(SSLProtocol protocol)
{
	pimpl->sslProtocol(protocol);
	return *this;
}
	
ClientBuilder& ClientBuilder::sslCiphers(const std::string& cipherList)
{
	pimpl->sslCiphers(cipherList);
	return *this;
}
	
ClientBuilder& ClientBuilder::sslVerify(bool verify)
{
	pimpl->sslVerify(verify);
	return *this;
}
	
ClientBuilder& ClientBuilder::sslVerificationDepth(int depth)
{
	pimpl->sslVerificationDepth(depth);
	return *this;
}
	
ClientBuilder& ClientBuilder::sslTrustStore(const std::string& pemFile)
{
	pimpl->sslTrustStore(pemFile);
	return *this;
}
	
ClientBuilder& ClientBuilder::sslDefaultCAs(bool useDefaultCAs)
{
	pimpl->sslDefaultCAs(useDefaultCAs);
	return *this;
}
	
ClientBuilder& ClientBuilder::sslKeyStore(const std::string& pkcs12File, const std::string& password)
{
	pimpl->sslKeyStore(pkcs12File, password);
	return *this;
}

std::shared_ptr<Client> ClientBuilder::build()
{
	return std::move(pimpl->build());
}
	
} // namespace JXXRS
