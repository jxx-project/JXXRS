//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/AuthRequest.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

AuthRequest::AuthRequest()
{
}

AuthRequest::AuthRequest(const JXXON::Json &json) :
		auth(json.get<decltype(auth)>("auth"))
{
}

JXXON::Json AuthRequest::toJson() const
{
	JXXON::Json json;
	json.set("auth", auth);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
