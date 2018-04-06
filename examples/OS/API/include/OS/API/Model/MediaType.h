//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_API_Model_MediaType_INCLUDED
#define OS_API_Model_MediaType_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS {
namespace API {
namespace Model {

struct MediaType : public JXXON::Serializable
{
	MediaType();
	MediaType(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> base;
	std::shared_ptr<std::string> type;
};

} // namespace Model
} // namespace API
} // namespace OS

#endif // OS_API_Model_MediaType_INCLUDED
