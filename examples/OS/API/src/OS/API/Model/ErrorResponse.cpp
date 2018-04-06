//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/API/Model/ErrorResponse.h"

namespace OS {
namespace API {
namespace Model {

ErrorResponse::ErrorResponse()
{
}

ErrorResponse::ErrorResponse(const JXXON::Json &json) :
		error(json.get<std::shared_ptr<Error>>("error"))
{
}

JXXON::Json ErrorResponse::toJson() const
{
	JXXON::Json json;
	json.set("error", error);
	return json;
}

} // namespace Model
} // namespace API
} // namespace OS
