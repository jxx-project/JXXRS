//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V2/Model/Role.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

Role::Role()
{
}

Role::Role(const JXXON::Json &json) :
		name(json.get<decltype(name)>("name"))
{
}

JXXON::Json Role::toJson() const
{
	JXXON::Json json;
	json.set("name", name);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
