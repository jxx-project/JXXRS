//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V3_Model_Links_INCLUDED
#define OS_Keystone_V3_Model_Links_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V3 { namespace Model {

struct Links : public JXXON::Serializable
{
	Links();
	Links(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> self;
};

}}}} // namespace OS::Keystone::V3::Model

#endif // OS_Keystone_V3_Model_Links_INCLUDED
