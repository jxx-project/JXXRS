//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_PoolingConnectionFactory_INCLUDED
#define JXXRS_PoolingConnectionFactory_INCLUDED

#include "JXXRS/ConnectionFactory.h"
#include <memory>

namespace JXXRS {

class PoolingConnectionFactory : public ConnectionFactory
{
public:
	PoolingConnectionFactory(size_t maxConnections = 20, bool keepAlive = true);
	virtual ~PoolingConnectionFactory();

	virtual std::unique_ptr<Connection> get(
		const Configuration& configuration,
		const std::string& scheme,
		const std::string& host,
		std::uint16_t port) override;

private:
	std::unique_ptr<ConnectionFactory> pimpl;
};

} // namespace JXXRS

#endif // JXXRS_PoolingConnectionFactory_INCLUDED
