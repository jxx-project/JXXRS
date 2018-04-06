//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V3_Model_ErrorResponse_INCLUDED
#define OS_Keystone_V3_Model_ErrorResponse_INCLUDED

#include "OS/Keystone/V3/Model/Error.h"
#include <JXXON/Serializable.h>

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

struct ErrorResponse : public JXXON::Serializable
{
	ErrorResponse();
	ErrorResponse(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Error> error;
};

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS

#endif // OS_Keystone_V3_Model_ErrorResponse_INCLUDED
