//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Role.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

Role::Role()
{
}

Role::Role(const JXXON::Json &json) :
		name(json.get<std::shared_ptr<std::string>>("name"))
{
}

JXXON::Json Role::toJson() const
{
	JXXON::Json json;
	json.set("name", name);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
