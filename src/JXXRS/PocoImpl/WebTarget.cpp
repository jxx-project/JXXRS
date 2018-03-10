//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/WebTarget.hpp"
#include "JXXRS/PocoImpl/Invocation.hpp"
#include <sstream>

namespace JXXRS {
namespace PocoImpl {

WebTarget::WebTarget(const Poco::URI& uri, std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory) :
		uri(uri), connectionFactory(connectionFactory)
{
}

WebTarget::~WebTarget() {
}

JXXRS::WebTarget& WebTarget::path(const std::string& path)
{
	const std::string currentPath = uri.getPath();
	uri.setPath(currentPath + (currentPath.back() == '/' || path.front() == '/' ? "" : "/") + path);
	return *this;
}

JXXRS::WebTarget& WebTarget::queryParam(const std::string& name, const std::string& value)
{
	uri.addQueryParameter(name, value);
	return *this;
}

std::unique_ptr<JXXRS::Invocation::Builder> WebTarget::request()
{
	return std::unique_ptr<JXXRS::Invocation::Builder>(
		new JXXRSPoco::Invocation::Builder(uri, connectionFactory));
}

} // namespace PocoImpl
} // namespace JXXRS
