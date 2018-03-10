//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_WebTarget_INCLUDED
#define JXXRS_PocoImpl_WebTarget_INCLUDED

#include "JXXRS/ConnectionFactory.hpp"
#include "JXXRS/Invocation.hpp"
#include "JXXRS/WebTarget.hpp"
#include <Poco/URI.h>
#include <memory>

namespace JXXRS {
namespace PocoImpl {

struct WebTarget : public JXXRS::WebTarget
{

	WebTarget(const Poco::URI& uri, std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory);
	virtual ~WebTarget();

	virtual JXXRS::WebTarget& path(const std::string& path) override;
	virtual JXXRS::WebTarget& queryParam(const std::string& name, const std::string& value) override;
	virtual std::unique_ptr<JXXRS::Invocation::Builder> request() override;

private:
	
	Poco::URI uri;
	std::shared_ptr<JXXRS::ConnectionFactory> connectionFactory;
};

} // namespace PocoImpl
} // namespace JXXRS

#endif // JXXRS_PocoImpl_WebTarget_INCLUDED
