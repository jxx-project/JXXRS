//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_PocoImpl_BasicConnectionFactory_INCLUDED
#define JXXRS_PocoImpl_BasicConnectionFactory_INCLUDED

#include "JXXRS/ConnectionFactory.h"
#include "JXXRS/PocoImpl/HTTPClientSessionFactory.h"

namespace JXXRS { namespace PocoImpl {

class BasicConnectionFactory : public JXXRS::ConnectionFactory
{
public:
	BasicConnectionFactory();
	virtual ~BasicConnectionFactory();

	virtual std::unique_ptr<JXXRS::Connection> get(
		const JXXRS::Configuration& configuration,
		const std::string& scheme,
		const std::string& host,
		std::uint16_t port) override;

protected:
	BasicConnectionFactory(std::unique_ptr<HTTPClientSessionFactory> httpClientSessionFactory);

private:
	std::unique_ptr<HTTPClientSessionFactory> httpClientSessionFactory;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_BasicConnectionFactory_INCLUDED
