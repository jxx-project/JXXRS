//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V3_Model_AuthResponse_INCLUDED
#define OS_Keystone_V3_Model_AuthResponse_INCLUDED

#include "OS/Keystone/V3/Model/Token.h"
#include <JXXON/Serializable.h>

namespace OS { namespace Keystone { namespace V3 { namespace Model {

struct AuthResponse : public JXXON::Serializable
{
	AuthResponse();
	AuthResponse(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Token> token;
};

}}}} // namespace OS::Keystone::V3::Model

#endif // OS_Keystone_V3_Model_AuthResponse_INCLUDED
