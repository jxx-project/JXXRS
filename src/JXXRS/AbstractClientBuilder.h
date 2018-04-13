//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_AbstractClientBuilder_INCLUDED
#define JXXRS_AbstractClientBuilder_INCLUDED

#include "JXXRS/Client.h"
#include "JXXRS/Configuration.h"
#include <memory>
#include <string>

namespace JXXRS {

class AbstractClientBuilder
{
public:
	virtual ~AbstractClientBuilder()
	{
	}

	virtual void property(const std::string& name, std::shared_ptr<Configuration::Object>&& value) = 0;
	virtual void property(const std::string& name, const std::string& value) = 0;
	virtual void property(const std::string& name, int value) = 0;
	virtual void property(const std::string& name, bool value) = 0;
	virtual std::shared_ptr<const Configuration> getConfiguration() = 0;
	virtual std::shared_ptr<Client> build() = 0;
};

} // namespace JXXRS

#endif // JXXRS_AbstractClientBuilder_INCLUDED
