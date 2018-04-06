//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V2_Model_Token_INCLUDED
#define OS_Keystone_V2_Model_Token_INCLUDED

#include "OS/Keystone/V2/Model/Tenant.h"
#include <JXXON/Serializable.h>
#include <string>

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

struct Token : public JXXON::Serializable
{
	Token();
	Token(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> id;
	std::shared_ptr<Tenant> tenant;
	std::shared_ptr<std::string> issuedAt;
	std::shared_ptr<std::string> expires;
};

} // namespace Model
} // namespace V2
} // namespace Keystone
} // namespace OS

#endif // OS_Keystone_V2_Model_Token_INCLUDED
