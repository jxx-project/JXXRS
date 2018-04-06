//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "OS/API/Error.h"

using namespace std;

namespace OS {
namespace API {

Error::Error(const std::string& what) : std::runtime_error(what)
{
}

Error::Error(int status) : runtime_error("HTTP Status " + std::to_string(status))
{
}

Error::Error(const std::shared_ptr<Model::Error> error) : runtime_error(error ? error->toJson().toString() : "Unknown error")
{
}

} // namespace API
} // namespace OS
