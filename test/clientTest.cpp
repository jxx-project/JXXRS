#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "JXXRS/ClientBuilder.h"
#include "Mock/BasicConnectionFactory.h"

TEST_CASE("Default client", "[client]")
{
	JXXRS::ClientBuilder clientBuilder;
        auto client = clientBuilder.property("connectionFactory", std::make_shared<Mock::BasicConnectionFactory>()).build();
	REQUIRE(client != nullptr);

	SECTION("Create target")
	{
		auto target = client->target("http://sample.server.org");
		REQUIRE(target != nullptr);
	}
}
