//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Identity.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

Identity::Identity()
{
}

Identity::Identity(const JXXON::Json &json) :
		methods(json.get<std::shared_ptr<JXXON::List<std::string>>>("methods")),
		password(json.get<std::shared_ptr<Password>>("password")),
		token(json.get<std::shared_ptr<Token>>("token")),
		challengeResponse(json.get<std::shared_ptr<ChallengeResponse>>("challenge-response"))
{
}

JXXON::Json Identity::toJson() const
{
	JXXON::Json json;
	json.set("methods", methods);
	json.set("password", password);
	json.set("token", token);
	json.set("challenge-response", challengeResponse);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
