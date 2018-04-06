//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Trust.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

Trust::Trust()
{
}

Trust::Trust(const JXXON::Json &json) :
		id(json.get<std::shared_ptr<std::string>>("id")),
		trusteeUserId(json.get<std::shared_ptr<std::string>>("trustee_user_id")),
		trustorUserId(json.get<std::shared_ptr<std::string>>("trustor_user_id")),
		impersonation(json.get<std::shared_ptr<bool>>("impersonation"))
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

} // namespace Model
} // namespace V2
} // namespace Keystone
} // namespace OS
