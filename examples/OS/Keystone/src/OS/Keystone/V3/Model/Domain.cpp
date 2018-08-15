//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V3/Model/Domain.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Domain::Domain()
{
}

Domain::Domain(const JXXON::Json& json) : id(json.get<decltype(id)>("id")), name(json.get<decltype(name)>("name"))
{
}

JXXON::Json Domain::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("name", name);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
