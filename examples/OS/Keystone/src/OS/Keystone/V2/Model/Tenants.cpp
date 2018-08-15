//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V2/Model/Tenants.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

Tenants::Tenants()
{
}

Tenants::Tenants(const JXXON::Json& json) :
	tenants(json.get<decltype(tenants)>("tenants")),
	tenantsLinks(json.get<decltype(tenantsLinks)>("tenants_links"))
{
}

JXXON::Json Tenants::toJson() const
{
	JXXON::Json json;
	json.set("tenants", tenants);
	json.set("tenants_links", tenantsLinks);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
