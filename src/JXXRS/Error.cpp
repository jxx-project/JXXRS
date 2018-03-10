//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/Error.hpp"

namespace JXXRS {

Error::Error(const std::string what) : std::runtime_error(what)
{
}

Error::~Error()
{
}

} // namespace JXXRS
