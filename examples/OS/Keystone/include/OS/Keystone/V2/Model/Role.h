//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V2_Model_Role_INCLUDED
#define OS_Keystone_V2_Model_Role_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

struct Role : public JXXON::Serializable
{
	Role();
	Role(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> name;
};

} // namespace Model
} // namespace V2
} // namespace Keystone
} // namespace OS

#endif // OS_Keystone_V2_Model_Role_INCLUDED
