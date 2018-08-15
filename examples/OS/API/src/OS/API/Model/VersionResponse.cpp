//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/API/Model/VersionResponse.h"

namespace OS { namespace API { namespace Model {

VersionResponse::VersionResponse()
{
}

VersionResponse::VersionResponse(const JXXON::Json& json) : version(json.get<decltype(version)>("version"))
{
}

JXXON::Json VersionResponse::toJson() const
{
	JXXON::Json json;
	json.set("version", version);
	return json;
}

}}} // namespace OS::API::Model
