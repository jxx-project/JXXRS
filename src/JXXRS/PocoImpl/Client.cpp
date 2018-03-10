//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/Client.hpp"
#include "JXXRS/PocoImpl/WebTarget.hpp"
#include <Poco/URI.h>

namespace JXXRS {
namespace PocoImpl {

Client::Client(std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory) : connectionFactory(connectionFactory) {
}

Client::~Client() {
}

std::shared_ptr<JXXRS::WebTarget> Client::target(const std::string& uri) const {
	return std::shared_ptr<WebTarget>(new JXXRSPoco::WebTarget(Poco::URI(uri), connectionFactory));
}

} // namespace PocoImpl
} // namespace JXXRS
