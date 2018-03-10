//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_Client_INCLUDED
#define JXXRS_PocoImpl_Client_INCLUDED

#include "JXXRS/Client.hpp"
#include "JXXRS/ConnectionFactory.hpp"

namespace JXXRS {
namespace PocoImpl {

struct Client : public JXXRS::Client
{
	Client(std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory);
	virtual ~Client();

	virtual std::shared_ptr<JXXRS::WebTarget> target(const std::string& uri) const;

private:

	std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory;
};

} // namespace PocoImpl
} // namespace JXXRS

#endif // JXXRS_PocoImpl_Client_INCLUDED
