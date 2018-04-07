//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/Keystone/V3/Model/Token.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Token::Token()
{
}

Token::Token(const JXXON::Json &json) :
		id(json.get<decltype(id)>("id")),
		issuedAt(json.get<decltype(issuedAt)>("issued_at")),
		expiresAt(json.get<decltype(expiresAt)>("expires_at")),
		methods(json.get<decltype(methods)>("methods")),
		user(json.get<decltype(user)>("user")),
		domain(json.get<decltype(domain)>("domain")),
		project(json.get<decltype(project)>("project")),
		endpoints(json.get<decltype(endpoints)>("endpoints")),
		catalog(json.get<decltype(catalog)>("catalog")),
		roles(json.get<decltype(roles)>("roles"))
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

}}}} // namespace OS::Keystone::V3::Model
