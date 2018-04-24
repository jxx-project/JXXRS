//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Model_EchoRequest_INCLUDED
#define Model_EchoRequest_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace Model {

struct EchoRequest : public JXXON::Serializable
{
	EchoRequest();
	EchoRequest(const std::string& property);
	EchoRequest(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::string property;
};

} // namespace Model

#endif // Model_EchoRequest_INCLUDED
