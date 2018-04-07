//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V2_Model_Trust_INCLUDED
#define OS_Keystone_V2_Model_Trust_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V2 { namespace Model {

struct Trust : public JXXON::Serializable
{
	Trust();
	Trust(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> id;
	std::shared_ptr<std::string> trusteeUserId;
	std::shared_ptr<std::string> trustorUserId;
	std::shared_ptr<bool> impersonation;
};

}}}} // namespace OS::Keystone::V2::Model

#endif // OS_Keystone_V2_Model_Trust_INCLUDED
