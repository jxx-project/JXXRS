//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef OS_API_Model_Version_INCLUDED
#define OS_API_Model_Version_INCLUDED

#include "OS/API/Model/Link.h"
#include "OS/API/Model/MediaType.h"
#include <JXXON/List.h>
#include <JXXON/Serializable.h>
#include <string>

namespace OS { namespace API { namespace Model {

struct Version : public JXXON::Serializable
{
	Version();
	Version(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> id;
	std::shared_ptr<std::string> status;
	std::shared_ptr<std::string> updated;
	std::shared_ptr<JXXON::List<Link>> links;
	std::shared_ptr<JXXON::List<MediaType>> mediaTypes;
};

}}} // namespace OS::API::Model

#endif // OS_API_Model_Version_INCLUDED
