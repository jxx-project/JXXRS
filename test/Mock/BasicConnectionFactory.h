//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Mock_BasicConnectionFactory_INCLUDED
#define Mock_BasicConnectionFactory_INCLUDED

#include "JXXRS/PocoImpl/BasicConnectionFactory.h"

namespace Mock {

class BasicConnectionFactory : public JXXRS::PocoImpl::BasicConnectionFactory
{
public:
	BasicConnectionFactory();
	virtual ~BasicConnectionFactory();
};

} // namespace Mock

#endif // Mock_BasicConnectionFactory_INCLUDED
