//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Model_EchoResponse_INCLUDED
#define Model_EchoResponse_INCLUDED

#include "Model/Header.h"
#include <JXXON/List.h>
#include <JXXON/Serializable.h>
#include <cstdint>
#include <string>

namespace Model {

struct EchoResponse : public JXXON::Serializable
{
	EchoResponse();
	EchoResponse(
		const std::string& sessionId,
		const std::string& host,
		std::uint16_t port,
		const std::string& method,
		const std::string& uri,
		const JXXON::List<Header>& requestHeaders,
		const std::string& requestBody);
	EchoResponse(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

    const Header& getRequestHeader(const std::string name) const;

	std::string sessionId;
	std::string host;
	std::uint16_t port;
	std::string method;
	std::string uri;
	JXXON::List<Header> requestHeaders;
	std::string requestBody;
};

} // namespace Model

#endif // Model_EchoResponse_INCLUDED
