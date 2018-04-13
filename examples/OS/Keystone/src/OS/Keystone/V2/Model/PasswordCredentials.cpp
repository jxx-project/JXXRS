//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V2/Model/PasswordCredentials.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

PasswordCredentials::PasswordCredentials()
{
}

PasswordCredentials::PasswordCredentials(const JXXON::Json &json) :
		username(json.get<decltype(username)>("username")),
		password(json.get<decltype(password)>("password"))
{
}

JXXON::Json PasswordCredentials::toJson() const
{
	JXXON::Json json;
	json.set("username", username);
	json.set("password", password);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
