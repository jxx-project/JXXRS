//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/BasicConnectionFactory.h"
#include "JXXRS/PocoImpl/Configuration.h"
#include "JXXRS/PocoImpl/Connection.h"
#include "JXXRS/PocoImpl/Session.h"
#include <iostream>

namespace JXXRS { namespace PocoImpl {

BasicConnectionFactory::BasicConnectionFactory() :
		httpClientSessionFactory(new HTTPClientSessionFactory)
{
}

BasicConnectionFactory::BasicConnectionFactory(std::unique_ptr<HTTPClientSessionFactory> httpClientSessionFactory) :
		httpClientSessionFactory(std::move(httpClientSessionFactory))
{
}

BasicConnectionFactory::~BasicConnectionFactory()
{
}

std::unique_ptr<JXXRS::Connection> BasicConnectionFactory::get(
	const JXXRS::Configuration& configuration,
	const std::string& scheme,
	const std::string& host,
	std::uint16_t port)
{
	auto config = dynamic_cast<const Configuration&>(configuration);
	return std::unique_ptr<Connection>(
		new Connection(
			std::make_shared<Session>(
				scheme,
				host,
				port,
				false,
				config.getSSLContext(),
				config.getProxyConfig(),
				*httpClientSessionFactory)));
}

}} // namespace JXXRS::PocoImpl
