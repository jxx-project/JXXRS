//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Password.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

Password::Password()
{
}

Password::Password(const JXXON::Json &json) :
		user(json.get<std::shared_ptr<User>>("user"))
{
}

JXXON::Json Password::toJson() const
{
	JXXON::Json json;
	json.set("user", user);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
