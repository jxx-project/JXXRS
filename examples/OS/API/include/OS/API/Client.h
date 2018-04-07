//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_API_Client_INCLUDED
#define OS_API_Client_INCLUDED

#include "OS/API/Model/Version.h"
#include <JXXRS/Client.h>
#include <string>

namespace OS { namespace API {

class Client
{
public:
	Client(std::shared_ptr<JXXRS::Client> client);
	std::shared_ptr<Model::Version> getVersion(const std::string& uri) const;
	std::shared_ptr<JXXON::List<Model::Version>> getVersions(const std::string& uri) const;
	std::pair<std::shared_ptr<Model::Version>, std::shared_ptr<JXXON::List<Model::Version>>> get(const std::string& uri) const;

private:
	std::shared_ptr<JXXRS::Client> client;
};

}} // namespace OS::API

#endif // OS_API_Client_INCLUDED
