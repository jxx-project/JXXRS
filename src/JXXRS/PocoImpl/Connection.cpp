//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/Connection.h"
#include "JXXRS/PocoImpl/Request.h"
#include "JXXRS/PocoImpl/Response.h"
#include <Poco/Net/HTTPResponse.h>

namespace JXXRS { namespace PocoImpl {

Connection::Connection(std::shared_ptr<Session> session) : session(session), out(nullptr), in(nullptr)
{
	session->acquire();
}

Connection::~Connection()
{
	if (session) {
		try {
			if (out) {
				if (!in) {
					Poco::Net::HTTPResponse dummy;
					in = &session->getHTTPClientSession().receiveResponse(dummy);
				}
				// drain the response before releasing the session
				while (in->good()) {
					char buf[1024];
					in->read(buf, sizeof(buf));
				}
			}
		} catch (...) {
			session->getHTTPClientSession().reset();
		}
		session->release();
	}
}

std::ostream& Connection::sendRequest(std::unique_ptr<JXXRS::Request> request)
{
	if (out) {
		throw std::logic_error("JXXRS::PocoImpl::Connection::sendRequest: already sent");
	} else {
		out = &session->getHTTPClientSession().sendRequest(dynamic_cast<Request*>(request.get())->getHTTPRequest());
		return *out;
	}
}

std::istream& Connection::receiveResponse(JXXRS::Response& response)
{
	if (in) {
		throw std::logic_error("JXXRS::PocoImpl::Connection::receiveResponse: already received");
	} else {
		in = &session->getHTTPClientSession().receiveResponse(dynamic_cast<Response&>(response).getHTTPResponse());
		return *in;
	}
}

}} // namespace JXXRS::PocoImpl
