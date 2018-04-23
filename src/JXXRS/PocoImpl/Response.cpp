//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/PocoImpl/Response.h"
#include <Poco/Exception.h>

namespace JXXRS { namespace PocoImpl {

Response::Response(std::unique_ptr<JXXRS::Connection> connection) : connection(std::move(connection))
{
	in = &this->connection->receiveResponse(*this);
}

Response::~Response()
{
}

int Response::getStatus() const
{
	return httpResponse.getStatus();
}

std::unique_ptr<std::string> Response::getHeaderString(const std::string& name) const
{
	try {
		return std::unique_ptr<std::string>(new std::string(httpResponse.get(name)));
	} catch (Poco::NotFoundException& e) {
		return nullptr;
	}
}

std::unique_ptr<std::string> Response::getMediaType() const
{
	auto result =  std::unique_ptr<std::string>(new std::string(httpResponse.getContentType()));
	if (*result == Poco::Net::HTTPMessage::UNKNOWN_CONTENT_TYPE) {
		return nullptr;
	}
	return result;
}

JXXON::Json Response::getJson() const
{
	JXXON::Json json;
	*in >> json;
	return json;
}

}} // namespace JXXRS::PocoImpl
