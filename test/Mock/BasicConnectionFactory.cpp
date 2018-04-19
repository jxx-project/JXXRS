//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Mock/BasicConnectionFactory.h"
#include "Mock/HTTPClientSessionFactory.h"

namespace Mock {

BasicConnectionFactory::BasicConnectionFactory() :
		JXXRS::PocoImpl::BasicConnectionFactory(std::unique_ptr<HTTPClientSessionFactory>(new HTTPClientSessionFactory))
{
}

BasicConnectionFactory::~BasicConnectionFactory()
{
}

} // namespace Mock
