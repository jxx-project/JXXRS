//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Mock/HTTPClientSessionFactory.h"
#include "JXXRS/Error.h"
#include "Mock/HTTPClientSession.h"

namespace Mock {

HTTPClientSessionFactory::HTTPClientSessionFactory()
{
}

HTTPClientSessionFactory::~HTTPClientSessionFactory()
{
}

std::unique_ptr<Poco::Net::HTTPClientSession> HTTPClientSessionFactory::get(
	const std::string& scheme,
	const std::string& host,
	std::uint16_t port,
	const Poco::Net::Context::Ptr sslContext) const
{
	if (scheme == "http") {
		return std::unique_ptr<Poco::Net::HTTPClientSession>(new HTTPClientSession(host, port));
	} else if (scheme == "https") {
		return std::unique_ptr<Poco::Net::HTTPClientSession>(new HTTPClientSession(host, port, sslContext));
	} else {
		throw JXXRS::Error("Mock::HTTPClientSessionFactory::get: Unknown scheme \"" + scheme + "\"");
	}
}

} // namespace Mock
