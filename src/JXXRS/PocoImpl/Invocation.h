//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_Invocation_INCLUDED
#define JXXRS_PocoImpl_Invocation_INCLUDED

#include "JXXRS/Invocation.h"
#include "JXXRS/PocoImpl/Configuration.h"
#include "JXXRS/Request.h"
#include "JXXRS/Response.h"
#include <Poco/URI.h>
#include <map>
#include <set>

namespace JXXRS { namespace PocoImpl {

class Invocation : public JXXRS::Invocation
{
public:
	class Builder : public JXXRS::Invocation::Builder {
	public:
		Builder(const Poco::URI& uri, std::shared_ptr<Configuration> configuration);
		virtual ~Builder();

		virtual JXXRS::Invocation::Builder& accept(const std::string& mediaType) override;
		virtual JXXRS::Invocation::Builder& header(const std::string& name, const std::string& value) override;
		virtual std::unique_ptr<JXXRS::Invocation> build(const std::string& method) const override;
		virtual std::unique_ptr<JXXRS::Invocation> build(
			const std::string& method, std::unique_ptr<JXXRS::Entity> entity) const override;
		virtual std::unique_ptr<JXXRS::Invocation> buildGet() const override;
		virtual std::unique_ptr<JXXRS::Invocation> buildDelete() const override;
		virtual std::unique_ptr<JXXRS::Invocation> buildPost(std::unique_ptr<Entity> entity) const override;
		virtual std::unique_ptr<JXXRS::Invocation> buildPut(std::unique_ptr<Entity> entity) const override;

	private:
		Poco::URI uri;
		std::shared_ptr<Configuration> configuration;
		std::set<std::string> acceptedMediaTypes;
		std::multimap<std::string, std::string> headers;
	};

	Invocation(
		const std::string& method,
		const Poco::URI& uri,
		const std::set<std::string>& acceptedMediaTypes,
		const std::multimap<std::string, std::string>& headers,
		std::shared_ptr<Configuration> configuration);
	Invocation(const Invocation& other) = delete;
	Invocation& operator=(const Invocation& other) = delete;
	virtual ~Invocation();

	virtual std::unique_ptr<JXXRS::Response> invoke() override;

private:
	Poco::URI uri;
	std::unique_ptr<JXXRS::Request> request;
	std::unique_ptr<JXXRS::Entity> requestEntity;
	std::shared_ptr<Configuration> configuration;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_Invocation_INCLUDED
