//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V2_Model_ErrorResponse_INCLUDED
#define OS_Keystone_V2_Model_ErrorResponse_INCLUDED

#include "OS/API/Model/Error.h"
#include <JXXON/Serializable.h>

namespace OS { namespace Keystone { namespace V2 { namespace Model {

struct ErrorResponse : public JXXON::Serializable
{
	ErrorResponse();
	ErrorResponse(const JXXON::Json& json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<OS::API::Model::Error> error;
};

}}}} // namespace OS::Keystone::V2::Model

#endif // OS_Keystone_V2_Model_ErrorResponse_INCLUDED
