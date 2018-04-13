//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_PocoImpl_HTTPClientSessionFactory_INCLUDED
#define JXXRS_PocoImpl_HTTPClientSessionFactory_INCLUDED

#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPClientSession.h>
#include <cstdint>
#include <memory>
#include <string>

namespace JXXRS { namespace PocoImpl {

class HTTPClientSessionFactory
{
public:
	HTTPClientSessionFactory();
	~HTTPClientSessionFactory();

	virtual std::unique_ptr<Poco::Net::HTTPClientSession> get(
		const std::string& scheme,
		const std::string& host,
		std::uint16_t port,
		const Poco::Net::Context::Ptr sslContext) const;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_HTTPClientSessionFactory_INCLUDED
