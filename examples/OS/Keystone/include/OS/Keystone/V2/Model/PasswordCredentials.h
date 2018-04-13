//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V2_Model_PasswordCredentials_INCLUDED
#define OS_Keystone_V2_Model_PasswordCredentials_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V2 { namespace Model {

struct PasswordCredentials : public JXXON::Serializable
{
	PasswordCredentials();
	PasswordCredentials(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> username;
	std::shared_ptr<std::string> password;
};

}}}} // namespace OS::Keystone::V2::Model

#endif // OS_Keystone_V2_Model_PasswordCredentials_INCLUDED
