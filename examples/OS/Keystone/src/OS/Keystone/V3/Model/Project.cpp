//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V3/Model/Project.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Project::Project()
{
}

Project::Project(const JXXON::Json &json) :
		id(json.get<decltype(id)>("id")),
		name(json.get<decltype(name)>("name")),
		domain(json.get<decltype(domain)>("domain")),
		links(json.get<decltype(links)>("links"))
{
}

JXXON::Json Project::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("name", name);
	json.set("domain", domain);
	json.set("links", links);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
