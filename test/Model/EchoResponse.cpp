//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/EchoResponse.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>

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

EchoResponse::EchoResponse(const JXXON::Json& json) :
	sessionId(json.get<decltype(sessionId)>("sessionId")),
	host(json.get<decltype(host)>("host")),
	port(json.get<decltype(port)>("port")),
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
	json.set("port", port);
	json.set("method", method);
	json.set("uri", uri);
	json.set("requestHeaders", requestHeaders);
	json.set("requestBody", requestBody);
	return json;
}

const Header& EchoResponse::getRequestHeader(const std::string name) const
{
	for (auto& i : requestHeaders) {
		if (std::equal(name.begin(), name.end(), i.name.begin(), [](int lhs, int rhs) {
				return std::toupper(lhs) == std::toupper(rhs);
			})) {
			return i;
		}
	}
	throw std::runtime_error("Request header\"" + name + "\" not found.");
}

} // namespace Model
