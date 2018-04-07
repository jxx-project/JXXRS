//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Trust.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

Trust::Trust()
{
}

Trust::Trust(const JXXON::Json &json) :
		id(json.get<decltype(id)>("id")),
		trusteeUserId(json.get<decltype(trusteeUserId)>("trustee_user_id")),
		trustorUserId(json.get<decltype(trustorUserId)>("trustor_user_id")),
		impersonation(json.get<decltype(impersonation)>("impersonation"))
{
}

JXXON::Json Trust::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("trustee_user_id", trusteeUserId);
	json.set("trustor_user_id", trustorUserId);
	json.set("impersonation", impersonation);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
