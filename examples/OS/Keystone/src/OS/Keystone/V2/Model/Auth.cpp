//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V2/Model/Auth.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

Auth::Auth()
{
}

Auth::Auth(const JXXON::Json& json) :
	tenantName(json.get<decltype(tenantName)>("tenantName")),
	tenantId(json.get<decltype(tenantId)>("tenantId")),
	passwordCredentials(json.get<decltype(passwordCredentials)>("passwordCredentials")),
	token(json.get<decltype(token)>("token"))
{
}

JXXON::Json Auth::toJson() const
{
	JXXON::Json json;
	json.set("tenantName", tenantName);
	json.set("tenantId", tenantId);
	json.set("passwordCredentials", passwordCredentials);
	json.set("token", token);
	return json;
}
}}}} // namespace OS::Keystone::V2::Model
