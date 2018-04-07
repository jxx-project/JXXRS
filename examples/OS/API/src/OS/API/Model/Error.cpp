//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/API/Model/Error.h"

namespace OS { namespace API { namespace Model {

Error::Error()
{
}

Error::Error(const JXXON::Json &json) :
		code(json.get<decltype(code)>("code")),
		title(json.get<decltype(title)>("title")),
		message(json.get<decltype(message)>("message"))
{
}

JXXON::Json Error::toJson() const
{
	JXXON::Json json;
	json.set("code", code);
	json.set("title", title);
	json.set("message", message);
	return json;
}

}}} // namespace OS::API::Model
