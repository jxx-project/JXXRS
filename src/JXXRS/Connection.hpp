//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_Connection_INCLUDED
#define JXXRS_Connection_INCLUDED

#include "JXXRS/Request.hpp"
#include "JXXRS/Response.hpp"
#include <memory>
#include <ostream>
#include <istream>

namespace JXXRS {

struct Connection
{
	virtual ~Connection()
	{
	}

	virtual std::ostream& sendRequest(std::unique_ptr<Request> request) = 0;
	virtual std::istream& receiveResponse(Response& response) = 0;
};

} // namespace JXXRS

#endif // JXXRS_Connection_INCLUDED
