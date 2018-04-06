//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Service.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

Service::Service()
{
}

Service::Service(const JXXON::Json &json) :
		type(json.get<std::shared_ptr<std::string>>("type")),
		name(json.get<std::shared_ptr<std::string>>("name")),
		endpoints(json.get<std::shared_ptr<JXXON::List<Endpoint>>>("endpoints")),
		endpointsLinks(json.get<std::shared_ptr<JXXON::List<std::string>>>("endpoints_links"))
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

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
