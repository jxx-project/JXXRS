//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_PocoImpl_WebTarget_INCLUDED
#define JXXRS_PocoImpl_WebTarget_INCLUDED

#include "JXXRS/Invocation.h"
#include "JXXRS/PocoImpl/Configuration.h"
#include "JXXRS/WebTarget.h"
#include <Poco/URI.h>
#include <memory>

namespace JXXRS { namespace PocoImpl {

class WebTarget : public JXXRS::WebTarget
{
public:
	WebTarget(const Poco::URI& uri, std::shared_ptr<const Configuration> configuration);
	virtual ~WebTarget();

	virtual JXXRS::WebTarget& path(const std::string& path) override;
	virtual JXXRS::WebTarget& queryParam(const std::string& name, const std::string& value) override;
	virtual std::unique_ptr<JXXRS::Invocation::Builder> request() override;

private:
	Poco::URI uri;
	std::shared_ptr<const Configuration> configuration;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_WebTarget_INCLUDED
