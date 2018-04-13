//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V2/Model/Service.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

Service::Service()
{
}

Service::Service(const JXXON::Json &json) :
		type(json.get<decltype(type)>("type")),
		name(json.get<decltype(name)>("name")),
		endpoints(json.get<decltype(endpoints)>("endpoints")),
		endpointsLinks(json.get<decltype(endpointsLinks)>("endpoints_links"))
{
}

JXXON::Json Service::toJson() const
{
	JXXON::Json json;
	json.set("type", type);
	json.set("name", name);
	json.set("endpoints", endpoints);
	json.set("endpoints_links", endpointsLinks);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
