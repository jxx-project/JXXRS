//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/API/Model/Link.h"

namespace OS { namespace API { namespace Model {

Link::Link()
{
}

Link::Link(const JXXON::Json &json) :
		href(json.get<decltype(href)>("href")),
		rel(json.get<decltype(rel)>("rel")),
		type(json.get<decltype(type)>("type"))
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

}}} // namespace OS::API::Model
