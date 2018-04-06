//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Token.h"

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

Token::Token()
{
}

Token::Token(const JXXON::Json &json) :
		id(json.get<std::shared_ptr<std::string>>("id")),
		issuedAt(json.get<std::shared_ptr<std::string>>("issued_at")),
		expiresAt(json.get<std::shared_ptr<std::string>>("expires_at")),
		methods(json.get<std::shared_ptr<JXXON::List<std::string>>>("methods")),
		user(json.get<std::shared_ptr<User>>("user")),
		domain(json.get<std::shared_ptr<Domain>>("domain")),
		project(json.get<std::shared_ptr<Project>>("project")),
		endpoints(json.get<std::shared_ptr<JXXON::List<Endpoint>>>("endpoints")),
		catalog(json.get<std::shared_ptr<JXXON::List<Service>>>("catalog")),
		roles(json.get<std::shared_ptr<JXXON::List<Role>>>("roles"))
{
}

JXXON::Json Token::toJson() const
{
	JXXON::Json json;
	json.set("id", id);
	json.set("issued_at", issuedAt);
	json.set("expires_at", expiresAt);
	json.set("methods", methods);
	json.set("user", user);
	json.set("domain", domain);
	json.set("project", project);
	json.set("endpoints", endpoints);
	json.set("catalog", catalog);
	json.set("roles", roles);
	return json;
}

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS
