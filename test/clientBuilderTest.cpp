#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "JXXRS/ClientBuilder.h"
#include "JXXRS/PocoImpl/BasicConnectionFactory.h"
#include "Mock/HTTPClientSessionFactory.h"

TEST_CASE("Create default client", "[clientBuilder]")
{
	auto client = JXXRS::ClientBuilder::newClient();
	REQUIRE(client != nullptr);
}

TEST_CASE("Assign connection factory", "[clientBuilder]")
{
	JXXRS::ClientBuilder clientBuilder;
	auto configBefore = clientBuilder.getConfiguration();
	clientBuilder.property("connectionFactory", std::make_shared<JXXRS::PocoImpl::BasicConnectionFactory>());
	auto configAfter = clientBuilder.getConfiguration();
	REQUIRE(configAfter != configBefore);
}
