//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Service.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

Service::Service()
{
}

Service::Service(const JXXON::Json &json) :
		id(json.get<std::shared_ptr<std::string>>("id")),
		name(json.get<std::shared_ptr<std::string>>("name")),
		type(json.get<std::shared_ptr<std::string>>("type")),
		endpoints(json.get<std::shared_ptr<JXXON::List<Endpoint>>>("endpoints")),
		links(json.get<std::shared_ptr<Links>>("links"))
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

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
