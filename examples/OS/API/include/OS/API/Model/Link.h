//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_API_Model_Link_INCLUDED
#define OS_API_Model_Link_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace API { namespace Model {

struct Link : public JXXON::Serializable
{
	Link();
	Link(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> href;
	std::shared_ptr<std::string> rel;
	std::shared_ptr<std::string> type;
};

}}} // namespace OS::API::Model

#endif // OS_API_Model_Link_INCLUDED
