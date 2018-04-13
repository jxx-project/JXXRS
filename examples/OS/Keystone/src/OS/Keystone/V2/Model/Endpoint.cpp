//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V2/Model/Endpoint.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

Endpoint::Endpoint()
{
}

Endpoint::Endpoint(const JXXON::Json &json) :
		id(json.get<decltype(id)>("id")),
		region(json.get<decltype(region)>("region")),
		adminUrl(json.get<decltype(adminUrl)>("adminURL")),
		internalUrl(json.get<decltype(internalUrl)>("internalURL")),
		publicUrl(json.get<decltype(publicUrl)>("publicURL"))
{
}

JXXON::Json Endpoint::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("region", region);
	json.set("adminURL", adminUrl);
	json.set("internalURL", internalUrl);
	json.set("publicURL", publicUrl);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
