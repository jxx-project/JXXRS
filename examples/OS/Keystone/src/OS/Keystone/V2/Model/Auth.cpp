//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Auth.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

Auth::Auth()
{
}

Auth::Auth(const JXXON::Json &json) :
		tenantName(json.get<std::shared_ptr<std::string>>("tenantName")),
		tenantId(json.get<std::shared_ptr<std::string>>("tenantId")),
		passwordCredentials(json.get<std::shared_ptr<PasswordCredentials>>("passwordCredentials")),
		token(json.get<std::shared_ptr<Token>>("token"))
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
} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
