//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/AuthResponse.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

AuthResponse::AuthResponse()
{
}

AuthResponse::AuthResponse(const JXXON::Json &json) :
		token(json.get<decltype(token)>("token"))
{
}

JXXON::Json AuthResponse::toJson() const
{
	JXXON::Json json;
	json.set("token", token);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
