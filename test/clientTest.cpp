#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "JXXRS/ClientBuilder.h"
#include "Mock/BasicConnectionFactory.h"
#include "Model/EchoResponse.h"

TEST_CASE("Default client", "[client]")
{
	JXXRS::ClientBuilder clientBuilder;
		auto client = clientBuilder.property("connectionFactory", std::make_shared<Mock::BasicConnectionFactory>()).build();
	REQUIRE(client != nullptr);

	SECTION("Create target")
	{
		auto target = client->target("http://example.server.org");
		REQUIRE(target != nullptr);

		SECTION("Build request")
		{
			auto invocationBuilder = target->request();
			REQUIRE(invocationBuilder != nullptr);

			SECTION("Build invocation")
			{
				auto invocation = invocationBuilder->buildGet();
				REQUIRE(invocation != nullptr);

				SECTION("Get response.")
				{
					auto response = invocation->invoke();
					REQUIRE(response != nullptr);

					SECTION("Get entity.")
					{
						auto entity = response->getEntity<Model::EchoResponse>();
						REQUIRE(entity.host == "example.server.org");
					}
				}
			}
		}
	}
}
