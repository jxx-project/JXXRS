//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V3/Model/Role.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Role::Role()
{
}

Role::Role(const JXXON::Json& json) :
	id(json.get<decltype(id)>("id")),
	name(json.get<decltype(name)>("name")),
	links(json.get<decltype(links)>("links"))
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

}}}} // namespace OS::Keystone::V3::Model
