//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_API_Model_Error_INCLUDED
#define OS_API_Model_Error_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS {
namespace API {
namespace Model {

struct Error : public JXXON::Serializable
{
	Error();
	Error(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<int> code;
	std::shared_ptr<std::string> title;
	std::shared_ptr<std::string> message;
};

} // namespace Model
} // namespace API
} // namespace OS

#endif // OS_API_Model_Error_INCLUDED
