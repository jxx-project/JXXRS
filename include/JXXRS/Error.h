//
// Copyright (c) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_Error_INCLUDED
#define JXXRS_Error_INCLUDED

#include <stdexcept>

namespace JXXRS {

class Error : public std::runtime_error
{
public:
	Error(const std::string what);
	virtual ~Error();
};

} // namespace JXXRS

#endif // JXXRS_Error_INCLUDED
