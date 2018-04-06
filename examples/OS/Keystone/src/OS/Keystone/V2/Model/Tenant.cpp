//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Tenant.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

Tenant::Tenant()
{
}

Tenant::Tenant(const JXXON::Json &json) :
		id(json.get<std::shared_ptr<std::string>>("id")),
		name(json.get<std::shared_ptr<std::string>>("name")),
		description(json.get<std::shared_ptr<std::string>>("description")),
		enabled(json.get<std::shared_ptr<bool>>("enabled"))
{
}

JXXON::Json Tenant::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("name", name);
	json.set("description", description);
	json.set("enabled", enabled);
	return json;
}

} // namespace Model
} // namespace V2
} // namespace Keystone
} // namespace OS
