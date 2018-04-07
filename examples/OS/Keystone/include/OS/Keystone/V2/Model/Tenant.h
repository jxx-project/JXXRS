//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V2_Model_Tenant_INCLUDED
#define OS_Keystone_V2_Model_Tenant_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V2 { namespace Model {

struct Tenant : public JXXON::Serializable
{
	Tenant();
	Tenant(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> id;
	std::shared_ptr<std::string> name;
	std::shared_ptr<std::string> description;
	std::shared_ptr<bool> enabled;
};

}}}} // namespace OS::Keystone::V2::Model

#endif // OS_Keystone_V2_Model_Tenant_INCLUDED
