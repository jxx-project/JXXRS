//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/API/Model/Link.h"

namespace OS {
namespace API {
namespace Model {

Link::Link()
{
}

Link::Link(const JXXON::Json &json) :
		href(json.get<std::shared_ptr<std::string>>("href")),
		rel(json.get<std::shared_ptr<std::string>>("rel")),
		type(json.get<std::shared_ptr<std::string>>("type"))
{
}

JXXON::Json Link::toJson() const
{
	JXXON::Json json;
	json.set("href", href);
	json.set("rel", rel);
	json.set("type", type);
	return json;
}

} // namespace Model
} // namespace API
} // namespace OS
