#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "JXXRS/ClientBuilder.h"
#include "Mock/BasicConnectionFactory.h"
#include "Model/EchoRequest.h"
#include "Model/EchoResponse.h"
#include <sstream>

JXXRS::ClientBuilder clientBuilder;
auto client = clientBuilder.property("connectionFactory", std::make_shared<Mock::BasicConnectionFactory>()).build();

TEST_CASE("HTTP target", "[http]")
{
	auto target = client->target("http://example.server.org");
	REQUIRE(target != nullptr);

	SECTION("Build request")
	{
		Model::EchoRequest echoRequest("example");
		auto invocationBuilder = target->request();
		REQUIRE(invocationBuilder != nullptr);

		SECTION("Build GET invocation")
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
					REQUIRE(entity.port == 80);
					REQUIRE(entity.method == "GET");
				}
			}
		}

		SECTION("Build json entity POST invocation")
		{
			auto invocation = invocationBuilder->buildPost(JXXRS::Entity::json(echoRequest));
			REQUIRE(invocation != nullptr);

			SECTION("Get response.")
			{
				auto response = invocation->invoke();
				REQUIRE(response != nullptr);

				SECTION("Get entity.")
				{
					auto entity = response->getEntity<Model::EchoResponse>();
					REQUIRE(entity.host == "example.server.org");
					REQUIRE(entity.port == 80);
					REQUIRE(entity.method == "POST");
					REQUIRE(entity.getRequestHeader("Content-Type").value == "application/json");
					REQUIRE(entity.requestBody == echoRequest.toJson().toString());
				}
			}
		}

		SECTION("Build text entity POST invocation")
		{
			auto invocation = invocationBuilder->buildPost(JXXRS::Entity::text(echoRequest.toJson().toString()));
			REQUIRE(invocation != nullptr);

			SECTION("Get response.")
			{
				auto response = invocation->invoke();
				REQUIRE(response != nullptr);

				SECTION("Get entity.")
				{
					auto entity = response->getEntity<Model::EchoResponse>();
					REQUIRE(entity.host == "example.server.org");
					REQUIRE(entity.port == 80);
					REQUIRE(entity.method == "POST");
					REQUIRE(entity.getRequestHeader("Content-Type").value == "text/plain");
					REQUIRE(entity.requestBody == echoRequest.toJson().toString());
				}
			}
		}

		SECTION("Build stream entity POST invocation")
		{
			auto in = std::unique_ptr<std::istringstream>(new std::istringstream(echoRequest.toJson().toString()));
			auto invocation = invocationBuilder->buildPost(JXXRS::Entity::stream(std::move(in)));
			REQUIRE(invocation != nullptr);

			SECTION("Get response.")
			{
				auto response = invocation->invoke();
				REQUIRE(response != nullptr);

				SECTION("Get entity.")
				{
					auto entity = response->getEntity<Model::EchoResponse>();
					REQUIRE(entity.host == "example.server.org");
					REQUIRE(entity.port == 80);
					REQUIRE(entity.method == "POST");
					REQUIRE(entity.getRequestHeader("Content-Type").value == "application/octet-stream");
					REQUIRE(entity.requestBody == echoRequest.toJson().toString());
				}
			}
		}

		SECTION("Build json entity PUT invocation")
		{
			auto invocation = invocationBuilder->buildPut(JXXRS::Entity::json(echoRequest));
			REQUIRE(invocation != nullptr);

			SECTION("Get response.")
			{
				auto response = invocation->invoke();
				REQUIRE(response != nullptr);

				SECTION("Get entity.")
				{
					auto entity = response->getEntity<Model::EchoResponse>();
					REQUIRE(entity.host == "example.server.org");
					REQUIRE(entity.port == 80);
					REQUIRE(entity.method == "PUT");
					REQUIRE(entity.requestBody == echoRequest.toJson().toString());
				}
			}
		}

		SECTION("Build text entity PUT invocation")
		{
			auto invocation = invocationBuilder->buildPut(JXXRS::Entity::text(echoRequest.toJson().toString()));
			REQUIRE(invocation != nullptr);

			SECTION("Get response.")
			{
				auto response = invocation->invoke();
				REQUIRE(response != nullptr);

				SECTION("Get entity.")
				{
					auto entity = response->getEntity<Model::EchoResponse>();
					REQUIRE(entity.host == "example.server.org");
					REQUIRE(entity.port == 80);
					REQUIRE(entity.method == "PUT");
					REQUIRE(entity.getRequestHeader("Content-Type").value == "text/plain");
					REQUIRE(entity.requestBody == echoRequest.toJson().toString());
				}
			}
		}

		SECTION("Build stream entity PUT invocation")
		{
			auto in = std::unique_ptr<std::istringstream>(new std::istringstream(echoRequest.toJson().toString()));
			auto invocation = invocationBuilder->buildPut(JXXRS::Entity::stream(std::move(in)));
			REQUIRE(invocation != nullptr);

			SECTION("Get response.")
			{
				auto response = invocation->invoke();
				REQUIRE(response != nullptr);

				SECTION("Get entity.")
				{
					auto entity = response->getEntity<Model::EchoResponse>();
					REQUIRE(entity.host == "example.server.org");
					REQUIRE(entity.port == 80);
					REQUIRE(entity.method == "PUT");
					REQUIRE(entity.getRequestHeader("Content-Type").value == "application/octet-stream");
					REQUIRE(entity.requestBody == echoRequest.toJson().toString());
				}
			}
		}

		SECTION("Build DELETE invocation")
		{
			auto invocation = invocationBuilder->buildDelete();
			REQUIRE(invocation != nullptr);

			SECTION("Get response.")
			{
				auto response = invocation->invoke();
				REQUIRE(response != nullptr);

				SECTION("Get entity.")
				{
					auto entity = response->getEntity<Model::EchoResponse>();
					REQUIRE(entity.host == "example.server.org");
					REQUIRE(entity.port == 80);
					REQUIRE(entity.method == "DELETE");
				}
			}
		}
	}
}
