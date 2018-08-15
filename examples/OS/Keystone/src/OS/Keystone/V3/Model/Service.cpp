//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V3/Model/Service.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Service::Service()
{
}

Service::Service(const JXXON::Json& json) :
	id(json.get<decltype(id)>("id")),
	name(json.get<decltype(name)>("name")),
	type(json.get<decltype(type)>("type")),
	endpoints(json.get<decltype(endpoints)>("endpoints")),
	links(json.get<decltype(links)>("links"))
{
}

JXXON::Json Service::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("name", name);
	json.set("type", type);
	json.set("endpoints", endpoints);
	json.set("links", links);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
