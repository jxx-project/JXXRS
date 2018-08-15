//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Mock_HTTPClientSessionFactory_INCLUDED
#define Mock_HTTPClientSessionFactory_INCLUDED

#include "JXXRS/PocoImpl/HTTPClientSessionFactory.h"

namespace Mock {

class Connection;

class HTTPClientSessionFactory : public JXXRS::PocoImpl::HTTPClientSessionFactory
{
public:
	HTTPClientSessionFactory();
	~HTTPClientSessionFactory();

	virtual std::unique_ptr<Poco::Net::HTTPClientSession>
	get(const std::string& scheme, const std::string& host, std::uint16_t port, const Poco::Net::Context::Ptr sslContext) const;
};

} // namespace Mock

#endif // Mock_HTTPClientSessionFactory_INCLUDED
