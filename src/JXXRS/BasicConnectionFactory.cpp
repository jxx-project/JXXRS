//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/BasicConnectionFactory.h"
#include "JXXRS/PocoImpl/BasicConnectionFactory.h"

namespace JXXRS {

BasicConnectionFactory::BasicConnectionFactory() : pimpl(new PocoImpl::BasicConnectionFactory)
{
}

BasicConnectionFactory::~BasicConnectionFactory()
{
}

std::unique_ptr<Connection> BasicConnectionFactory::get(
	const Configuration& configuration, const std::string& scheme, const std::string& host, std::uint16_t port)
{
	return pimpl->get(configuration, scheme, host, port);
}

} // namespace JXXRS
