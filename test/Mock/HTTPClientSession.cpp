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
			id: id.str(),
			host: host,
			port: port,
			method: method,
			uri: uri,
			requestHeaders: requestHeaders,
			requestBody: requestStream.str()
		};
}

} // namespace Mock
