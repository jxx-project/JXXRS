//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V3/Model/Links.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Links::Links()
{
}

Links::Links(const JXXON::Json& json) : self(json.get<decltype(self)>("self"))
{
}

JXXON::Json Links::toJson() const
{
	JXXON::Json json;
	json.set("self", self);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
