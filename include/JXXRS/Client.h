//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_Client_INCLUDED
#define JXXRS_Client_INCLUDED

#include "JXXRS/WebTarget.h"
#include <memory>
#include <string>

namespace JXXRS {

class Client
{
public:
	virtual ~Client()
	{
	}

	virtual std::shared_ptr<WebTarget> target(const std::string& uri) const = 0;
};

} // namespace JXXRS

#endif // JXXRS_Client_INCLUDED
