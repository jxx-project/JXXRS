//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_API_Model_ErrorResponse_INCLUDED
#define OS_API_Model_ErrorResponse_INCLUDED

#include "OS/API/Model/Error.h"
#include <JXXON/Serializable.h>

namespace OS { namespace API { namespace Model {

struct ErrorResponse : public JXXON::Serializable
{
	ErrorResponse();
	ErrorResponse(const JXXON::Json& json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Error> error;
};

}}} // namespace OS::API::Model

#endif // OS_API_Model_ErrorResponse_INCLUDED
