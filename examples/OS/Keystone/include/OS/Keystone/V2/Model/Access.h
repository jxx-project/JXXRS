//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_Keystone_V2_Model_Access_INCLUDED
#define OS_Keystone_V2_Model_Access_INCLUDED

#include "OS/Keystone/V2/Model/Token.h"
#include "OS/Keystone/V2/Model/Service.h"
#include "OS/Keystone/V2/Model/User.h"
#include "OS/Keystone/V2/Model/Metadata.h"
#include "OS/Keystone/V2/Model/Trust.h"
#include <JXXON/List.h>
#include <JXXON/Serializable.h>

namespace OS { namespace Keystone { namespace V2 { namespace Model {

struct Access : public JXXON::Serializable
{
	Access();
	Access(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<Token> token;
	std::shared_ptr<JXXON::List<Service>> serviceCatalog;
	std::shared_ptr<User> user;
	std::shared_ptr<Metadata> metadata;
	std::shared_ptr<Trust> trust;
};

}}}} // namespace OS::Keystone::V2::Model

#endif // OS_Keystone_V2_Model_Access_INCLUDED
