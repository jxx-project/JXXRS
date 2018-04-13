//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/PocoImpl/Invocation.h"
#include "JXXRS/MediaType.h"
#include "JXXRS/PocoImpl/Request.h"
#include "JXXRS/PocoImpl/Response.h"
#include <Poco/Net/HTTPMessage.h>
#include <Poco/Net/HTTPRequest.h>

namespace JXXRS { namespace PocoImpl {

Invocation::Builder::Builder
(const Poco::URI& uri, std::shared_ptr<Configuration> configuration) :
		uri(uri), configuration(configuration)
{
}

Invocation::Builder::~Builder()
{
}

JXXRS::Invocation::Builder& Invocation::Builder::accept(const std::string& mediaType)
{
	acceptedMediaTypes.emplace(mediaType);
	return *this;
}

JXXRS::Invocation::Builder& Invocation::Builder::header(const std::string& name, const std::string& value)
{
	headers.emplace(name, value);
	return *this;
}

std::unique_ptr<JXXRS::Invocation> Invocation::Builder::build(const std::string& method) const
{
	std::unique_ptr<Invocation> invocation(new Invocation(method, uri, acceptedMediaTypes, headers, configuration));
	return invocation;
}

std::unique_ptr<JXXRS::Invocation> Invocation::Builder::build(
	const std::string& method, std::unique_ptr<Entity> entity) const
{
	std::unique_ptr<Invocation> invocation(new Invocation(method, uri, acceptedMediaTypes, headers, configuration));
	invocation->request->setContentType(entity->getMediaType());
	invocation->request->setChunkedTransferEncoding(true);
	invocation->request->setKeepAlive(true);
	invocation->requestEntity = std::move(entity);
	return invocation;
}

std::unique_ptr<JXXRS::Invocation> Invocation::Builder::buildGet() const
{
	return build(Poco::Net::HTTPRequest::HTTP_GET);
}

std::unique_ptr<JXXRS::Invocation> Invocation::Builder::buildDelete() const
{
	return build(Poco::Net::HTTPRequest::HTTP_DELETE);
}

std::unique_ptr<JXXRS::Invocation> Invocation::Builder::buildPost(std::unique_ptr<Entity> entity) const
{
	return build(Poco::Net::HTTPRequest::HTTP_POST, std::move(entity));
}

std::unique_ptr<JXXRS::Invocation> Invocation::Builder::buildPut(std::unique_ptr<Entity> entity) const
{
	return build(Poco::Net::HTTPRequest::HTTP_PUT, std::move(entity));
}

Invocation::Invocation(
	const std::string& method,
	const Poco::URI& uri,
	const std::set<std::string> &acceptedMediaTypes,
	const std::multimap<std::string, std::string>& headers,
	std::shared_ptr<Configuration> configuration) :
		uri(uri),
		request(std::unique_ptr<Request>(new Request(method, uri.getPathAndQuery(), Poco::Net::HTTPMessage::HTTP_1_1))),
		configuration(configuration)
{
	for (auto i = acceptedMediaTypes.begin(); i != acceptedMediaTypes.end(); ++i) {
		request->addHeader("Accept", *i);
	}
	for (auto i = headers.begin(); i != headers.end(); ++i) {
		request->addHeader(i->first, i->second);
	}
	request->setHost(uri.getHost(), uri.getPort());
}

Invocation::~Invocation()
{
}

std::unique_ptr<JXXRS::Response> Invocation::invoke()
{
	auto connection = configuration->getConnectionFactory().get(*configuration, uri.getScheme(), uri.getHost(), uri.getPort());
	std::ostream& out = connection->sendRequest(std::move(request));
	if (requestEntity) {
		out << *requestEntity;
	}
	return std::unique_ptr<JXXRS::Response>(new JXXRS::PocoImpl::Response(std::move(connection)));
}

}} // namespace JXXRS::PocoImpl
