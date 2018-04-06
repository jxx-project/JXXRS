//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Auth.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

Auth::Auth()
{
}

Auth::Auth(const JXXON::Json &json) :
		identity(json.get<std::shared_ptr<Identity>>("identity")),
		scope(json.get<std::shared_ptr<Scope>>("scope"))
{
}

JXXON::Json Auth::toJson() const
{
	JXXON::Json json;
	json.set("identity", identity);
	json.set("scope", scope);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
