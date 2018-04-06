//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V3_Model_Error_INCLUDED
#define OS_Keystone_V3_Model_Error_INCLUDED

#include "OS/API/Model/Error.h"
#include "OS/Keystone/V3/Model/Identity.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

struct Error : public OS::API::Model::Error
{
	Error();
	Error(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Identity> identity;
};

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS

#endif // OS_Keystone_V3_Model_Error_INCLUDED
