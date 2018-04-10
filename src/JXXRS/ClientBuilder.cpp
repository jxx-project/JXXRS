//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/ClientBuilder.h"
#include "JXXRS/PocoImpl/ClientBuilder.h"

namespace JXXRS {

ClientBuilder::ClientBuilder() : pimpl(new PocoImpl::ClientBuilder)
{
}

ClientBuilder& ClientBuilder::property(const std::string& name, std::shared_ptr<Configuration::Object>&& value)
{
	pimpl->property(name, std::move(value));
	return *this;
}

ClientBuilder& ClientBuilder::property(const std::string& name, const std::string& value)
{
	pimpl->property(name, value);
	return *this;
}

ClientBuilder& ClientBuilder::property(const std::string& name, int value)
{
	pimpl->property(name, value);
	return *this;
}

ClientBuilder& ClientBuilder::property(const std::string& name, bool value)
{
	pimpl->property(name, value);
	return *this;
}

std::shared_ptr<Client> ClientBuilder::build()
{
	return pimpl->build();
}

std::shared_ptr<Client> ClientBuilder::newClient()
{
	return PocoImpl::ClientBuilder().build();
}

} // namespace JXXRS
