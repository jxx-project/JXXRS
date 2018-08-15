//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V2_Model_Metadata_INCLUDED
#define OS_Keystone_V2_Model_Metadata_INCLUDED

#include <JXXON/List.h>
#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace Keystone { namespace V2 { namespace Model {

struct Metadata : public JXXON::Serializable
{
	Metadata();
	Metadata(const JXXON::Json& json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<int> isAdmin;
	std::shared_ptr<JXXON::List<std::string>> roles;
};

}}}} // namespace OS::Keystone::V2::Model

#endif // OS_Keystone_V2_Model_Metadata_INCLUDED
