//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_Configurable_INCLUDED
#define JXXRS_Configurable_INCLUDED

#include "JXXRS/Configuration.h"
#include <memory>
#include <string>

namespace JXXRS {

template<typename T>
class Configurable
{
public:
	virtual ~Configurable()
	{
	}

	virtual T& property(const std::string& name, std::shared_ptr<Configuration::Object> value) = 0;
	virtual T& property(const std::string& name, const std::string& value) = 0;
	virtual T& property(const std::string& name, int value) = 0;
	virtual T& property(const std::string& name, bool value) = 0;
};

} // namespace JXXRS

#endif // JXXRS_Configurable_INCLUDED
