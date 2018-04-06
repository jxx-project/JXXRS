//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/AuthResponse.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

AuthResponse::AuthResponse()
{
}

AuthResponse::AuthResponse(const JXXON::Json &json) :
		access(json.get<std::shared_ptr<Access>>("access"))
{
}

JXXON::Json AuthResponse::toJson() const
{
	JXXON::Json json;
	json.set("access", access);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS