//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Model_Header_INCLUDED
#define Model_Header_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace Model {

struct Header : public JXXON::Serializable
{
	Header();
	Header(const std::string& name, const std::string& value);
	Header(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::string name;
	std::string value;
};

} // namespace Model

#endif // Model_Header_INCLUDED
