//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/Header.h"

namespace Model {

Header::Header()
{
}

Header::Header(const std::string& name, const std::string& value) : name(name), value(value)
{
}

Header::Header(const JXXON::Json& json) : name(json.get<decltype(name)>("name")), value(json.get<decltype(value)>("value"))
{
}

JXXON::Json Header::toJson() const
{
	JXXON::Json json;
	json.set("name", name);
	json.set("value", value);
	return json;
}

} // namespace Model
