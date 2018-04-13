//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_ConnectionFactory_INCLUDED
#define JXXRS_ConnectionFactory_INCLUDED

#include "JXXRS/Configuration.h"
#include "JXXRS/Connection.h"
#include <memory>
#include <string>

namespace JXXRS {

class ConnectionFactory : public Configuration::Object
{
public:
	virtual ~ConnectionFactory()
	{
	}

	virtual std::unique_ptr<Connection> get(
		const Configuration& configuration,
		const std::string& scheme,
		const std::string& host,
		std::uint16_t port) = 0;
};

} // namespace JXXRS

#endif // JXXRS_ConnectionFactory_INCLUDED
