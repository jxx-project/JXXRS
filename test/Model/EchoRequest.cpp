//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/EchoRequest.h"

namespace Model {

EchoRequest::EchoRequest()
{
}

EchoRequest::EchoRequest(const std::string& property) :
		property(property)
{
}

EchoRequest::EchoRequest(const JXXON::Json &json) :
		property(json.get<decltype(property)>("property"))
{
}

JXXON::Json EchoRequest::toJson() const
{
	JXXON::Json json;
	json.set("property", property);
	return json;
}

} // namespace Model
