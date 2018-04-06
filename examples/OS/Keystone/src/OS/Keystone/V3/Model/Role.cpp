//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Role.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

Role::Role()
{
}

Role::Role(const JXXON::Json &json) :
		id(json.get<std::shared_ptr<std::string>>("id")),
		name(json.get<std::shared_ptr<std::string>>("name")),
		links(json.get<std::shared_ptr<Links>>("links"))
{
}

JXXON::Json Role::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("name", name);
	json.set("links", links);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
