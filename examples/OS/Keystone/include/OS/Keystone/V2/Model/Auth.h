//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V2_Model_Auth_INCLUDED
#define OS_Keystone_V2_Model_Auth_INCLUDED

#include "OS/Keystone/V2/Model/PasswordCredentials.h"
#include "OS/Keystone/V2/Model/Token.h"
#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V2 { namespace Model {

struct Auth : public JXXON::Serializable
{
	Auth();
	Auth(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> tenantName;
	std::shared_ptr<std::string> tenantId;
	std::shared_ptr<PasswordCredentials> passwordCredentials;
	std::shared_ptr<Token> token;
};

}}}} // namespace OS::Keystone::V2::Model

#endif // OS_Keystone_V2_Model_Auth_INCLUDED
