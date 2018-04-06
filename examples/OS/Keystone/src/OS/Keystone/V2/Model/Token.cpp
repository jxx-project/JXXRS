//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Token.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

Token::Token()
{
}

Token::Token(const JXXON::Json &json) :
		id(json.get<std::shared_ptr<std::string>>("id")),
		tenant(json.get<std::shared_ptr<Tenant>>("tenant")),
		issuedAt(json.get<std::shared_ptr<std::string>>("issued_at")),
		expires(json.get<std::shared_ptr<std::string>>("expires"))
{
}

JXXON::Json Token::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("tenant", tenant);
	json.set("issued_at", issuedAt);
	json.set("expires", expires);
	return json;
}

} // namespace Model
} // namespace V2
} // namespace Keystone
} // namespace OS
