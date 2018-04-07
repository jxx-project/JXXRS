//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V2_Model_Tenants_INCLUDED
#define OS_Keystone_V2_Model_Tenants_INCLUDED

#include "OS/Keystone/V2/Model/Tenant.h"
#include <JXXON/List.h>
#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V2 { namespace Model {

struct Tenants : public JXXON::Serializable
{
	Tenants();
	Tenants(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<JXXON::List<Tenant>> tenants;
	std::shared_ptr<JXXON::List<std::string>> tenantsLinks;
};

}}}} // namespace OS::Keystone::V2::Model

#endif // OS_Keystone_V2_Model_Tenants_INCLUDED
