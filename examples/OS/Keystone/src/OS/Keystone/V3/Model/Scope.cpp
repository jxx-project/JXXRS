//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Scope.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

Scope::Scope()
{
}

Scope::Scope(const JXXON::Json &json) :
		domain(json.get<std::shared_ptr<Domain>>("domain")),
		project(json.get<std::shared_ptr<Project>>("project"))
{
}

JXXON::Json Scope::toJson() const
{
	JXXON::Json json;
	json.set("domain", domain);
	json.set("project", project);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
