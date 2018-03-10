//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_Request_INCLUDED
#define JXXRS_Request_INCLUDED

#include <string>

namespace JXXRS {

struct Request
{
	virtual ~Request()
	{
	}

	virtual void addHeader(const std::string& name, const std::string& value) = 0;
	virtual void setChunkedTransferEncoding(bool flag) = 0;
	virtual void setContentType(const std::string& mediaType) = 0;
	virtual void setKeepAlive(bool keepAlive) = 0;
	virtual void setHost(const std::string& host, std::uint16_t port) = 0;
};

} // namespace JXXRS

#endif // JXXRS_Request_INCLUDED
