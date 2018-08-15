//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/API/Model/MediaType.h"

namespace OS { namespace API { namespace Model {

MediaType::MediaType()
{
}

MediaType::MediaType(const JXXON::Json& json) : base(json.get<decltype(base)>("base")), type(json.get<decltype(type)>("type"))
{
}

JXXON::Json MediaType::toJson() const
{
	JXXON::Json json;
	json.set("base", base);
	json.set("type", type);
	return json;
}

}}} // namespace OS::API::Model
