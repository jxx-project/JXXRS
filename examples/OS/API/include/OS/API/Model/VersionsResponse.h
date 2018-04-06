//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_API_Model_VersionsResponse_INCLUDED
#define OS_API_Model_VersionsResponse_INCLUDED

#include "OS/API/Model/Version.h"
#include <JXXON/List.h>
#include <JXXON/Serializable.h>

namespace OS {
namespace API {
namespace Model {

struct VersionsResponse : public JXXON::Serializable {
	VersionsResponse();
	VersionsResponse(const JXXON::Json &json);
	virtual JXXON::Json toJson() const override;

	std::shared_ptr<JXXON::List<Version>> versions;

private:
	struct Versions {
        Versions(const JXXON::Json &json);
        std::shared_ptr<JXXON::List<Version>> values;
	};
};

} // namespace Model
} // namespace API
} // namespace OS

#endif // OS_API_Model_VersionsResponse_INCLUDED
