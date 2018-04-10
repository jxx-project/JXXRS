#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "JXXRS/ClientBuilder.h"

TEST_CASE("Create default client", "[clientBuilder]")
{
	auto client = JXXRS::ClientBuilder::newClient();
	REQUIRE(client != nullptr);
}
