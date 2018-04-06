//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V3_Model_AuthRequest_INCLUDED
#define OS_Keystone_V3_Model_AuthRequest_INCLUDED

#include "OS/Keystone/V3/Model/Auth.h"
#include <JXXON/Serializable.h>

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

struct AuthRequest : public JXXON::Serializable
{
	AuthRequest();
	AuthRequest(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Auth> auth;
};

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS

#endif // OS_Keystone_V3_Model_AuthRequest_INCLUDED
