//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_Invocation_INCLUDED
#define JXXRS_Invocation_INCLUDED

#include "JXXRS/Entity.h"
#include <memory>
#include <string>

namespace JXXRS {

class Response;

class Invocation
{
public:
	class Builder
	{
	public:
		virtual ~Builder()
		{
		}

		virtual Builder& accept(const std::string& mediaType) = 0;
		virtual Builder& header(const std::string& name, const std::string& value) = 0;
		virtual std::unique_ptr<Invocation> build(const std::string& method) const = 0;
		virtual std::unique_ptr<Invocation> build(const std::string& method, std::unique_ptr<Entity> entity) const = 0;
		virtual std::unique_ptr<Invocation> buildGet() const = 0;
		virtual std::unique_ptr<Invocation> buildDelete() const = 0;
		virtual std::unique_ptr<Invocation> buildPost(std::unique_ptr<Entity> entity) const = 0;
		virtual std::unique_ptr<Invocation> buildPut(std::unique_ptr<Entity> entity) const = 0;
	};

	virtual ~Invocation()
	{
	}

	virtual std::unique_ptr<Response> invoke() = 0;
};

} // namespace JXXRS

#endif // JXXRS_Invocation_INCLUDED
