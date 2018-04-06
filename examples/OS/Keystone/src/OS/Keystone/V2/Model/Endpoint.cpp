//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Endpoint.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

Endpoint::Endpoint()
{
}

Endpoint::Endpoint(const JXXON::Json &json) :
		id(json.get<std::shared_ptr<std::string>>("id")),
		region(json.get<std::shared_ptr<std::string>>("region")),
		adminUrl(json.get<std::shared_ptr<std::string>>("adminURL")),
		internalUrl(json.get<std::shared_ptr<std::string>>("internalURL")),
		publicUrl(json.get<std::shared_ptr<std::string>>("publicURL"))
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

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
