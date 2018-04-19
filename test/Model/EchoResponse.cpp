//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/EchoResponse.h"

namespace Model {

EchoResponse::EchoResponse()
{
}

EchoResponse::EchoResponse(
	const std::string& sessionId,
	const std::string& host,
	std::uint16_t port,
	const std::string& method,
	const std::string& uri,
	const JXXON::List<Header>& requestHeaders,
	const std::string& requestBody) :
		sessionId(sessionId),
		host(host),
		port(port),
		method(method),
		uri(uri),
		requestHeaders(requestHeaders),
		requestBody(requestBody)
{
}

EchoResponse::EchoResponse(const JXXON::Json &json) :
		sessionId(json.get<decltype(sessionId)>("sessionId")),
		host(json.get<decltype(host)>("host")),
		port(json.get<unsigned int>("port")),
		method(json.get<decltype(method)>("method")),
		uri(json.get<decltype(uri)>("uri")),
		requestHeaders(json.get<decltype(requestHeaders)>("requestHeaders")),
		requestBody(json.get<decltype(requestBody)>("requestBody"))
{
}

JXXON::Json EchoResponse::toJson() const
{
	JXXON::Json json;
	json.set("sessionId", sessionId);
	json.set("host", host);
	json.set<unsigned int>("port", port);
	json.set("method", method);
	json.set("uri", uri);
	json.set("requestHeaders", requestHeaders);
	json.set("requestBody", requestBody);
	return json;
}

} // namespace Model
