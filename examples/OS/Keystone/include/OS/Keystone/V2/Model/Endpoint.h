//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V2_Model_Endpoint_INCLUDED
#define OS_Keystone_V2_Model_Endpoint_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS {
namespace Keystone {
namespace V2 {
namespace Model {

struct Endpoint : public JXXON::Serializable
{
	Endpoint();
	Endpoint(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> id;
	std::shared_ptr<std::string> region;
	std::shared_ptr<std::string> adminUrl;
	std::shared_ptr<std::string> internalUrl;
	std::shared_ptr<std::string> publicUrl;
};

} // namespace Model
} // namespace V2
} // namespace Keystone
} // namespace OS

#endif // OS_Keystone_V2_Model_Endpoint_INCLUDED
