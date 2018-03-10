//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_Connection_INCLUDED
#define JXXRS_PocoImpl_Connection_INCLUDED

#include "JXXRS/Connection.hpp"
#include "JXXRS/PocoImpl/Session.hpp"
#include "JXXRS/Request.hpp"
#include "JXXRS/Response.hpp"
#include <memory>
#include <ostream>
#include <istream>

namespace JXXRS {
namespace PocoImpl {

struct Invocation;

struct Connection : public JXXRS::Connection
{
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

} // namespace PocoImpl
} // namespace JXXRS

#endif // JXXRS_PocoImpl_Connection_INCLUDED
