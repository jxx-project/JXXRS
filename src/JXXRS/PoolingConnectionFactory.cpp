//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/PoolingConnectionFactory.h"
#include "JXXRS/PocoImpl/PoolingConnectionFactory.h"

namespace JXXRS {

PoolingConnectionFactory::PoolingConnectionFactory(std::size_t maxSessions, bool keepAlive) :
	pimpl(new PocoImpl::PoolingConnectionFactory(maxSessions, keepAlive))
{
}

PoolingConnectionFactory::~PoolingConnectionFactory()
{
}

std::unique_ptr<Connection> PoolingConnectionFactory::get(
	const Configuration& configuration,
	const std::string& scheme,
	const std::string& host,
	std::uint16_t port)
{
	return pimpl->get(configuration, scheme, host, port);
}

} // namespace JXXRS
