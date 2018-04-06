//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/API/Model/MediaType.h"

namespace OS {
namespace API {
namespace Model {

MediaType::MediaType()
{
}

MediaType::MediaType(const JXXON::Json &json) :
		base(json.get<std::shared_ptr<std::string>>("base")),
		type(json.get<std::shared_ptr<std::string>>("type"))
{
}

JXXON::Json MediaType::toJson() const
{
	JXXON::Json json;
	json.set("base", base);
	json.set("type", type);
	return json;
}
  
} // namespace Model
} // namespace API
} // namespace OS
