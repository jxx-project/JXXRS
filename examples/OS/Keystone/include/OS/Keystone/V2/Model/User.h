//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V2_Model_User_INCLUDED
#define OS_Keystone_V2_Model_User_INCLUDED

#include "OS/Keystone/V2/Model/Role.h"
#include <JXXON/List.h>
#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V2 { namespace Model {

struct User : public JXXON::Serializable
{
	User();
	User(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> id;
	std::shared_ptr<std::string> username;
	std::shared_ptr<std::string> name;
	std::shared_ptr<JXXON::List<Role>> roles;
	std::shared_ptr<JXXON::List<std::string>> rolesLinks;
};

}}}} // namespace OS::Keystone::V2::Model

#endif // OS_Keystone_V2_Model_User_INCLUDED
