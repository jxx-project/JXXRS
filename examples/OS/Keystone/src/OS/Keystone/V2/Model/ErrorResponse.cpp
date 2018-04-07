//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/ErrorResponse.h"

namespace OS { namespace Keystone { namespace V2 { namespace Model {

ErrorResponse::ErrorResponse()
{
}

ErrorResponse::ErrorResponse(const JXXON::Json &json) :
		error(json.get<decltype(error)>("error"))
{
}

JXXON::Json ErrorResponse::toJson() const
{
	JXXON::Json json;
	json.set("error", error);
	return json;
}

}}}} // namespace OS::Keystone::V2::Model
