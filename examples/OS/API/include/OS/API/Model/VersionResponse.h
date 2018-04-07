//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_API_Model_VersionResponse_INCLUDED
#define OS_API_Model_VersionResponse_INCLUDED

#include "OS/API/Model/Version.h"
#include <JXXON/Serializable.h>

namespace OS { namespace API { namespace Model {

struct VersionResponse : public JXXON::Serializable
{
	VersionResponse();
	VersionResponse(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Version> version;
};

}}} // namespace OS::API::Model

#endif // OS_API_Model_VersionResponse_INCLUDED
