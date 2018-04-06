//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/User.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

User::User()
{
}

User::User(const JXXON::Json &json):
		id(json.get<std::shared_ptr<std::string>>("id")),
		username(json.get<std::shared_ptr<std::string>>("username")),
		name(json.get<std::shared_ptr<std::string>>("name")),
		roles(json.get<std::shared_ptr<JXXON::List<Role>>>("roles")),
		rolesLinks(json.get<std::shared_ptr<JXXON::List<std::string>>>("roles_links"))
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

} // namespace Model
} // namespace V2
} // namespace Keystone
} // namespace OS
