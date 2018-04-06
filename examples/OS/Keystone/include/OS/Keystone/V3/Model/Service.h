//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V3_Model_Service_INCLUDED
#define OS_Keystone_V3_Model_Service_INCLUDED

#include "OS/Keystone/V3/Model/Endpoint.h"
#include "OS/Keystone/V3/Model/Links.h"
#include <JXXON/List.h>
#include <JXXON/Serializable.h>
#include <string>

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

struct Service : public JXXON::Serializable
{
	Service();
	Service(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> id;
	std::shared_ptr<std::string> name;
	std::shared_ptr<std::string> type;
	std::shared_ptr<JXXON::List<Endpoint>> endpoints;
	std::shared_ptr<Links> links;
};

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS

#endif // OS_Keystone_V3_Model_Service_INCLUDED
