//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V3_Model_Role_INCLUDED
#define OS_Keystone_V3_Model_Role_INCLUDED

#include "OS/Keystone/V3/Model/Links.h"
#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V3 { namespace Model {

struct Role : public JXXON::Serializable
{
	Role();
	Role(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> id;
	std::shared_ptr<std::string> name;
	std::shared_ptr<Links> links;
};

}}}} // namespace OS::Keystone::V3::Model

#endif // OS_Keystone_V3_Model_Role_INCLUDED
