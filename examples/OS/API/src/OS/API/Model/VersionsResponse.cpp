//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/API/Model/VersionsResponse.h"

namespace OS { namespace API { namespace Model {

VersionsResponse::VersionsResponse()
{
}

VersionsResponse::VersionsResponse(const JXXON::Json &json)
{
	try {
        versions = json.get<std::shared_ptr<JXXON::List<Version>>>("versions");
	} catch (...) {
        // The keystone anomaly: Version objects are wrapped in a values array.
        versions = json.get<std::shared_ptr<Versions>>("versions")->values;
	}
}

JXXON::Json VersionsResponse::toJson() const
{
	JXXON::Json json;
	// We always write without the keystone anomaly..
	json.set("versions", versions);
	return json;
}

VersionsResponse::Versions::Versions(const JXXON::Json &json) :
		values(json.get<decltype(values)>("values"))
{
}

}}} // namespace OS::API::Model
