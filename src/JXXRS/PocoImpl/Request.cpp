//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/Request.h"

namespace JXXRS { namespace PocoImpl {

Request::Request(const std::string& httpMethod, const std::string& uri, const std::string& httpVersion) :
		httpRequest(httpMethod, uri, httpVersion)
{
}

Request::~Request()
{
}

void Request::addHeader(const std::string& name, const std::string& value)
{
	httpRequest.add(name, value);
}

void Request::setChunkedTransferEncoding(bool flag)
{
	httpRequest.setChunkedTransferEncoding(flag);
}

void Request::setContentType(const std::string& mediaType)
{
	httpRequest.setContentType(mediaType);
}

void Request::setKeepAlive(bool keepAlive)
{
	httpRequest.setKeepAlive(keepAlive);
}

void Request::setHost(const std::string& host, uint16_t port)
{
	httpRequest.setHost(host, port);
}

}} // namespace JXXRS::PocoImpl
