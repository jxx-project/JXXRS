//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_MediaType_INCLUDED
#define JXXRS_MediaType_INCLUDED

#include <string>

namespace JXXRS {

struct MediaType
{
	static const std::string APPLICATION_JSON;
	static const std::string APPLICATION_OCTET_STREAM;
};

} // namespace JXXRS

#endif // JXXRS_MediaType_INCLUDED
