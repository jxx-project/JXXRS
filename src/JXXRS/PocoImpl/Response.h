//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#ifndef JXXRS_PocoImpl_Response_INCLUDED
#define JXXRS_PocoImpl_Response_INCLUDED

#include <JXXON/Serializable.h>
#include "JXXRS/Connection.h"
#include "JXXRS/Response.h"
#include <Poco/Net/HTTPResponse.h>
#include <memory>
#include <string>

namespace JXXRS {
namespace PocoImpl {

class Connection;

class Response : public JXXRS::Response
{
public:
	Response(std::unique_ptr<JXXRS::Connection> connection);
	Response(const Response& other) = delete;
	Response(Response&& other);
	Response& operator=(const Response& other) = delete;
	Response& operator=(Response&& other);
	virtual ~Response();

	virtual int getStatus() const override;
	virtual std::unique_ptr<std::string> getHeaderString(const std::string& name) const override;
	virtual std::unique_ptr<std::string> getMediaType() const override;

	virtual std::istream& getStream() const {
		return *in;
	}
	Poco::Net::HTTPResponse& getHTTPResponse() {
		return httpResponse;
	}

protected:
	virtual JXXON::Json getJson() const override;

private:
	Poco::Net::HTTPResponse httpResponse;
	std::unique_ptr<JXXRS::Connection> connection;
	std::istream* in;
};

} // namespace PocoImpl
} // namespace JXXRS

#endif // JXXRS_PocoImpl_Response_INCLUDED
