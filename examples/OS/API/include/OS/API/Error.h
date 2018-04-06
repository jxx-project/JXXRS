//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef OS_API_Error_INCLUDED
#define OS_API_Error_INCLUDED

#include "OS/API/Model/Error.h"
#include <stdexcept>

namespace OS {
namespace API {

class Error : public std::runtime_error
{
public:
	Error(const std::string& what);
	Error(int status);
	Error(const std::shared_ptr<Model::Error> error);
};

} // namespace API
} // namespace OS

#endif // OS_API_Error_INCLUDED
