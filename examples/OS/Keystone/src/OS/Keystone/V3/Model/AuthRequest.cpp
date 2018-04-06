//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/AuthRequest.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

AuthRequest::AuthRequest()
{
}

AuthRequest::AuthRequest(const JXXON::Json &json) :
		auth(json.get<std::shared_ptr<Auth>>("auth"))
{
}

JXXON::Json AuthRequest::toJson() const
{
	JXXON::Json json;
	json.set("auth", auth);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
