#//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/API/Model/Version.h"

namespace OS {
namespace API {
namespace Model {

Version::Version()
{
}

Version::Version(const JXXON::Json &json) :
		id(json.get<std::shared_ptr<std::string>>("id")),
		status(json.get<std::shared_ptr<std::string>>("status")),
		updated(json.get<std::shared_ptr<std::string>>("updated")),
		links(json.get<std::shared_ptr<JXXON::List<Link>>>("links")),
		mediaTypes(json.get<std::shared_ptr<JXXON::List<MediaType>>>("media-types"))
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

} // namespace Model
} // namespace API
} // namespace OS
