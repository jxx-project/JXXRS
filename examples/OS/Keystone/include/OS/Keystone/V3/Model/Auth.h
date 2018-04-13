//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V3_Model_Auth_INCLUDED
#define OS_Keystone_V3_Model_Auth_INCLUDED

#include "OS/Keystone/V3/Model/Identity.h"
#include "OS/Keystone/V3/Model/Scope.h"
#include <JXXON/Serializable.h>

namespace OS { namespace Keystone { namespace V3 { namespace Model {

struct Auth : public JXXON::Serializable
{
	Auth();
	Auth(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Identity> identity;
	std::shared_ptr<Scope> scope;
};

}}}} // namespace OS::Keystone::V3::Model

#endif // OS_Keystone_V3_Model_Auth_INCLUDED
