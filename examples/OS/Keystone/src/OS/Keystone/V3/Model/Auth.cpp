//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Auth.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Auth::Auth()
{
}

Auth::Auth(const JXXON::Json &json) :
		identity(json.get<decltype(identity)>("identity")),
		scope(json.get<decltype(scope)>("scope"))
{
}

JXXON::Json Auth::toJson() const
{
	JXXON::Json json;
	json.set("identity", identity);
	json.set("scope", scope);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
