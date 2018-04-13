//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_WebTarget_INCLUDED
#define JXXRS_WebTarget_INCLUDED

#include "JXXRS/Invocation.h"
#include <memory>

namespace JXXRS {

class WebTarget
{
public:
	virtual ~WebTarget()
	{
	}

	virtual WebTarget& path(const std::string& path) = 0;
	virtual WebTarget& queryParam(const std::string& name, const std::string& value) = 0;
	template<typename T>
	WebTarget& queryParam(const std::string& name, const T& value)
	{
		return queryParam(name, std::to_string(value));
	}
	virtual std::unique_ptr<Invocation::Builder> request() = 0;
};

} // namespace JXXRS

#endif // JXXRS_WebTarget_INCLUDED
