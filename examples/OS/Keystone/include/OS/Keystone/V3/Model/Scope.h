//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V3_Model_Scope_INCLUDED
#define OS_Keystone_V3_Model_Scope_INCLUDED

#include "OS/Keystone/V3/Model/Domain.h"
#include "OS/Keystone/V3/Model/Project.h"
#include <JXXON/Serializable.h>

namespace OS { namespace Keystone { namespace V3 { namespace Model {

struct Scope : public JXXON::Serializable
{
	Scope();
	Scope(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Domain> domain;
	std::shared_ptr<Project> project;
};

}}}} // namespace OS::Keystone::V3::Model

#endif // OS_Keystone_V3_Model_Scope_INCLUDED
