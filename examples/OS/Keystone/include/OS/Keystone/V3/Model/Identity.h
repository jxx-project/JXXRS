//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V3_Model_Identity_INCLUDED
#define OS_Keystone_V3_Model_Identity_INCLUDED

#include "OS/Keystone/V3/Model/ChallengeResponse.h"
#include "OS/Keystone/V3/Model/Password.h"
#include "OS/Keystone/V3/Model/Token.h"
#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V3 { namespace Model {

struct Identity : public JXXON::Serializable
{
	Identity();
	Identity(const JXXON::Json& json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<JXXON::List<std::string>> methods;
	std::shared_ptr<Password> password;
	std::shared_ptr<Token> token;
	std::shared_ptr<ChallengeResponse> challengeResponse;
};

}}}} // namespace OS::Keystone::V3::Model

#endif // OS_Keystone_V3_Model_Identity_INCLUDED
