//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/Keystone/V3/Model/ChallengeResponse.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

ChallengeResponse::ChallengeResponse()
{
}

ChallengeResponse::ChallengeResponse(const JXXON::Json &json) :
		challenge(json.get<decltype(challenge)>("challenge")),
		sessionId(json.get<decltype(sessionId)>("session_id"))
{
}

JXXON::Json ChallengeResponse::toJson() const
{
	JXXON::Json json;
	json.set("challenge", challenge);
	json.set("session_id", sessionId);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
