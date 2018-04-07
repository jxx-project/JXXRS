//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/User.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

User::User()
{
}

User::User(const JXXON::Json &json):
		id(json.get<decltype(id)>("id")),
		username(json.get<decltype(username)>("username")),
		name(json.get<decltype(name)>("name")),
		roles(json.get<decltype(roles)>("roles")),
		rolesLinks(json.get<decltype(rolesLinks)>("roles_links"))
{
}

JXXON::Json User::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("username", username);
	json.set("name", name);
	json.set("roles", roles);
	json.set("roles_links", rolesLinks);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
