//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_Connection_INCLUDED
#define JXXRS_PocoImpl_Connection_INCLUDED

#include "JXXRS/Connection.h"
#include "JXXRS/PocoImpl/Session.h"
#include "JXXRS/Request.h"
#include "JXXRS/Response.h"
#include <memory>
#include <ostream>
#include <istream>

namespace JXXRS { namespace PocoImpl {

class Invocation;

class Connection : public JXXRS::Connection
{
public:
	Connection(std::shared_ptr<Session> session);
	virtual ~Connection();
	Connection(const Connection& other) = delete;
	Connection(Connection&& other) = delete;
	Connection& operator=(const Connection& other) = delete;
	Connection& operator=(Connection&& other) = delete;

	virtual std::ostream& sendRequest(std::unique_ptr<JXXRS::Request> request);
	virtual std::istream& receiveResponse(JXXRS::Response& response);

private:
	std::shared_ptr<Session> session;
	std::ostream* out;
	std::istream* in;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_Connection_INCLUDED
