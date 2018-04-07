//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Endpoint.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Endpoint::Endpoint()
{
}

Endpoint::Endpoint(const JXXON::Json &json) :
		id(json.get<decltype(id)>("id")),
		interface(json.get<decltype(interface)>("interface")),
		regionId(json.get<decltype(regionId)>("region_id")),
		serviceId(json.get<decltype(serviceId)>("service_id")),
		url(json.get<decltype(url)>("url")),
		links(json.get<decltype(links)>("links"))
{
}

JXXON::Json Endpoint::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("interface", interface);
	json.set("region_id", regionId);
	json.set("service_id", serviceId);
	json.set("url", url);
	json.set("links", links);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
