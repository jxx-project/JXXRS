//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/PocoImpl/Client.h"
#include "JXXRS/PocoImpl/WebTarget.h"
#include <Poco/URI.h>

namespace JXXRS { namespace PocoImpl {

Client::Client(std::shared_ptr<Configuration> configuration) : configuration(configuration)
{
}

Client::~Client()
{
}

std::shared_ptr<JXXRS::WebTarget> Client::target(const std::string& uri) const
{
	return std::shared_ptr<WebTarget>(new JXXRS::PocoImpl::WebTarget(Poco::URI(uri), configuration));
}

}} // namespace JXXRS::PocoImpl
