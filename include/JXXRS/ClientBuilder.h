//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_ClientBuilder_INCLUDED
#define JXXRS_ClientBuilder_INCLUDED

#include "JXXRS/Client.h"
#include "JXXRS/Configurable.h"
#include "JXXRS/Configuration.h"
#include <memory>
#include <string>

namespace JXXRS {

class AbstractClientBuilder;

class ClientBuilder : public Configurable<ClientBuilder>
{
public:
	ClientBuilder();
	virtual ~ClientBuilder();

	virtual ClientBuilder& property(const std::string& name, std::shared_ptr<Configuration::Object>&& value);
	virtual ClientBuilder& property(const std::string& name, const std::string& value);
	virtual ClientBuilder& property(const std::string& name, int value);
	virtual ClientBuilder& property(const std::string& name, bool value);
	virtual std::shared_ptr<Client> build();
	static std::shared_ptr<Client> newClient();

private:
	std::unique_ptr<AbstractClientBuilder> pimpl;
};

} // namespace JXXRS

#endif // JXXRS_ClientBuilder_INCLUDED
