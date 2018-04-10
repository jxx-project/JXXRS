//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Mock/HTTPClientSession.h"
#include "Model/EchoResponse.h"

namespace Mock {

HTTPClientSession::HTTPClientSession(const std::string& host, Poco::UInt16 port) :
		host(host), port(port)
{
}

HTTPClientSession::HTTPClientSession(const std::string& host, Poco::UInt16 port, Poco::Net::Context::Ptr sslContext) :
		host(host), port(port)
{
}

HTTPClientSession::~HTTPClientSession()
{
}

std::ostream& HTTPClientSession::sendRequest(Poco::Net::HTTPRequest& request)
{
	method = request.getMethod();
	uri = request.getURI();
	requestHeaders.clear();
	for (auto& i : request) {
		requestHeaders.emplace_back(Model::Header{name: i.first, value: i.second});
	}
}

std::istream& HTTPClientSession::receiveResponse(Poco::Net::HTTPResponse& response)
{
	std::ostringstream id;
	id << this;
	Model::EchoResponse responseBody =
		{
			id.str(),
			host,
			port,
			method,
			uri,
			requestHeaders,
			requestStream.str()
		};
}

} // namespace Mock
