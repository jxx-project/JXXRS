//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/User.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

User::User()
{
}

User::User(const JXXON::Json &json) :
		id(json.get<std::shared_ptr<std::string>>("id")),
		name(json.get<std::shared_ptr<std::string>>("name")),
		password(json.get<std::shared_ptr<std::string>>("password")),
		domain(json.get<std::shared_ptr<Domain>>("domain")),
		links(json.get<std::shared_ptr<Links>>("links"))
{
}

JXXON::Json User::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("name", name);
	json.set("password", password);
	json.set("domain", domain);
	json.set("links", links);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
