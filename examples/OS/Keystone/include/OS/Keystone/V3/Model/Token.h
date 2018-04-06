//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V3_Model_Token_INCLUDED
#define OS_Keystone_V3_Model_Token_INCLUDED

#include "OS/Keystone/V3/Model/User.h"
#include "OS/Keystone/V3/Model/Domain.h"
#include "OS/Keystone/V3/Model/Project.h"
#include "OS/Keystone/V3/Model/Endpoint.h"
#include "OS/Keystone/V3/Model/Service.h"
#include "OS/Keystone/V3/Model/Role.h"
#include <JXXON/Serializable.h>
#include <string>

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

struct Token : public JXXON::Serializable
{
	Token();
	Token(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> id;
	std::shared_ptr<std::string> issuedAt;
	std::shared_ptr<std::string> expiresAt;
	std::shared_ptr<JXXON::List<std::string>> methods;
	std::shared_ptr<User> user;
	std::shared_ptr<Domain> domain;
	std::shared_ptr<Project> project;
	std::shared_ptr<JXXON::List<Endpoint>> endpoints;
	std::shared_ptr<JXXON::List<Service>> catalog;
	std::shared_ptr<JXXON::List<Role>> roles;
};

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS

#endif // OS_Keystone_V3_Model_Token_INCLUDED
