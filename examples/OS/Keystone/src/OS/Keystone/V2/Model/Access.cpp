//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Access.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

Access::Access()
{
}

Access::Access(const JXXON::Json &json) :
		token(json.get<decltype(token)>("token")),
		serviceCatalog(json.get<decltype(serviceCatalog)>("serviceCatalog")),
		user(json.get<decltype(user)>("user")),
		metadata(json.get<decltype(metadata)>("metadata")),
		trust(json.get<decltype(trust)>("trust"))
{
}

JXXON::Json Access::toJson() const
{
	JXXON::Json json;
	json.set("token", token);
	json.set("serviceCatalog", serviceCatalog);
	json.set("user", user);
	json.set("metadata", metadata);
	json.set("trust", trust);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
