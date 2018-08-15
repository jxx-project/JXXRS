//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Mock_HTTPClientSession_INCLUDED
#define Mock_HTTPClientSession_INCLUDED

#include "Model/Header.h"
#include <JXXON/List.h>
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <cstdint>
#include <sstream>
#include <string>

namespace Mock {

class Connection;

/// Mock HTTPClientSession override. Echo request properties in a JSON response body.
class HTTPClientSession : public Poco::Net::HTTPClientSession
{
public:
	HTTPClientSession(const std::string& host, Poco::UInt16 port = Poco::Net::HTTPSession::HTTP_PORT);
	HTTPClientSession(const std::string& host, Poco::UInt16 port, Poco::Net::Context::Ptr sslContext);
	virtual ~HTTPClientSession();

	virtual std::ostream& sendRequest(Poco::Net::HTTPRequest& request);
	virtual std::istream& receiveResponse(Poco::Net::HTTPResponse& response);

private:
	std::string host;
	Poco::UInt16 port;
	std::string method;
	std::string uri;
	JXXON::List<Model::Header> requestHeaders;
	std::ostringstream requestStream;
	std::istringstream responseStream;
};

} // namespace Mock

#endif // Mock_HTTPClientSession_INCLUDED
