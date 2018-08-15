#//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/API/Model/Version.h"

namespace OS { namespace API { namespace Model {

Version::Version()
{
}

Version::Version(const JXXON::Json& json) :
	id(json.get<decltype(id)>("id")),
	status(json.get<decltype(status)>("status")),
	updated(json.get<decltype(updated)>("updated")),
	links(json.get<decltype(links)>("links")),
	mediaTypes(json.get<decltype(mediaTypes)>("media-types"))
{
}

JXXON::Json Version::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("status", status);
	json.set("updated", updated);
	json.set("links", links);
	json.set("media-types", mediaTypes);
	return json;
}

}}} // namespace OS::API::Model
