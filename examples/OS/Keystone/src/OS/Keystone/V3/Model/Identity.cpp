//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Identity.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Identity::Identity()
{
}

Identity::Identity(const JXXON::Json &json) :
		methods(json.get<decltype(methods)>("methods")),
		password(json.get<decltype(password)>("password")),
		token(json.get<decltype(token)>("token")),
		challengeResponse(json.get<decltype(challengeResponse)>("challenge-response"))
{
}

JXXON::Json Identity::toJson() const
{
	JXXON::Json json;
	json.set("methods", methods);
	json.set("password", password);
	json.set("token", token);
	json.set("challenge-response", challengeResponse);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
