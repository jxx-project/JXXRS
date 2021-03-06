//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V2/Model/Metadata.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

Keystone::V2::Model::Metadata::Metadata()
{
}

Metadata::Metadata(const JXXON::Json& json) :
	isAdmin(json.get<decltype(isAdmin)>("is_admin")),
	roles(json.get<decltype(roles)>("roles"))
{
}

JXXON::Json Metadata::toJson() const
{
	JXXON::Json json;
	json.set("is_admin", isAdmin);
	json.set("roles", roles);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
