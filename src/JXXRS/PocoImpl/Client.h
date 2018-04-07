//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_Client_INCLUDED
#define JXXRS_PocoImpl_Client_INCLUDED

#include "JXXRS/Client.h"
#include "JXXRS/PocoImpl/Configuration.h"

namespace JXXRS { namespace PocoImpl {

class Client : public JXXRS::Client
{
public:
	Client(std::shared_ptr<Configuration> configuration);
	virtual ~Client();

	virtual std::shared_ptr<JXXRS::WebTarget> target(const std::string& uri) const;

private:
	std::shared_ptr<Configuration> configuration;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_Client_INCLUDED
