//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V3_Model_Password_INCLUDED
#define OS_Keystone_V3_Model_Password_INCLUDED

#include "OS/Keystone/V3/Model/User.h"
#include <JXXON/Serializable.h>

namespace OS { namespace Keystone { namespace V3 { namespace Model {

struct Password : public JXXON::Serializable {
	Password();
	Password(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<User> user;
};

}}}} // namespace OS::Keystone::V3::Model

#endif // OS_Keystone_V3_Model_Password_INCLUDED
