//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V2/Model/Access.h"

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

Access::Access()
{
}

Access::Access(const JXXON::Json &json) :
		token(json.get<std::shared_ptr<Token>>("token")),
		serviceCatalog(json.get<std::shared_ptr<JXXON::List<Service>>>("serviceCatalog")),
		user(json.get<std::shared_ptr<User>>("user")),
		metadata(json.get<std::shared_ptr<Metadata>>("metadata")),
		trust(json.get<std::shared_ptr<Trust>>("trust"))
{
}

JXXON::Json Access::toJson() const
{
	JXXON::Json json;
	json.set("token", token);
	json.set("serviceCatalog", serviceCatalog);
	json.set("user", user);
	json.set("metadata", metadata);
	json.set("trust", trust);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
