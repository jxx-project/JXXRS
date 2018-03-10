//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_Request_INCLUDED
#define JXXRS_PocoImpl_Request_INCLUDED

#include "JXXRS/Request.hpp"
#include <Poco/Net/HTTPRequest.h>
#include <memory>
#include <string>

namespace JXXRS {
namespace PocoImpl {

struct Connection;

struct Request : public JXXRS::Request
{
	Request(const std::string& httpMethod, const std::string& uri, const std::string& httpVersion);
	Request(const Request& other) = delete;
	Request(Request&& other);
	Request& operator=(const Request& other) = delete;
	Request& operator=(Request&& other);
	virtual ~Request();

	virtual void addHeader(const std::string& name, const std::string& value) override;
	virtual void setChunkedTransferEncoding(bool flag) override;
	virtual void setContentType(const std::string& mediaType) override;
	virtual void setKeepAlive(bool keepAlive) override;
	virtual void setHost(const std::string& host, std::uint16_t port) override;
		
	Poco::Net::HTTPRequest& getHTTPRequest() {
		return httpRequest;
	}

private:

	Poco::Net::HTTPRequest httpRequest;
};

} // namespace PocoImpl
} // namespace JXXRS

#endif // JXXRS_PocoImpl_Request_INCLUDED
