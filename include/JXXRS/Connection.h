//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_Connection_INCLUDED
#define JXXRS_Connection_INCLUDED

#include "JXXRS/Request.h"
#include "JXXRS/Response.h"
#include <istream>
#include <memory>
#include <ostream>

namespace JXXRS {

class Connection
{
public:
	virtual ~Connection()
	{
	}

	virtual std::ostream& sendRequest(std::unique_ptr<Request> request) = 0;
	virtual std::istream& receiveResponse(Response& response) = 0;
};

} // namespace JXXRS

#endif // JXXRS_Connection_INCLUDED
