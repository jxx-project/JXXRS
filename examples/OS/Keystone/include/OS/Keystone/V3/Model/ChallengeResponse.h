//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_Keystone_V3_Model_ChallengeResponse_INCLUDED
#define OS_Keystone_V3_Model_ChallengeResponse_INCLUDED

#include <JXXON/Serializable.h>
#include <string>

namespace OS {
namespace Keystone {
namespace V3 {
namespace Model {

struct ChallengeResponse : public JXXON::Serializable
{
	ChallengeResponse();
	ChallengeResponse(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<std::string> challenge;
	std::shared_ptr<std::string> sessionId;
};

} // namespace Model
} // namespace V3
} // namespace Keystone
} // namespace OS

#endif // OS_Keystone_V3_Model_ChallengeResponse_INCLUDED
