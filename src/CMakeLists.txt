#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB SRCS_G JXXRS/*.cpp JXXRS/Accessor/*.cpp JXXRS/Poco/*.cpp)

add_library(jxxrs ${SRCS_G})

set_target_properties(jxxrs PROPERTIES PUBLIC_HEADER "JXXRS/ClientBuilder.hpp;JXXRS/Client.hpp;JXXRS/ConnectionFactory.hpp;JXXRS/Connection.hpp;JXXRS/Entity.hpp;JXXRS/Error.hpp;JXXRS/Invocation.hpp;JXXRS/JsonEntity.hpp;JXXRS/MediaType.hpp;JXXRS/Request.hpp;JXXRS/Response.hpp;JXXRS/SSLProtocol.hpp;JXXRS/StreamEntity.hpp;JXXRS/TextEntity.hpp;JXXRS/WebTarget.hpp")

install(TARGETS jxxrs
	ARCHIVE DESTINATION lib COMPONENT lib
	PUBLIC_HEADER DESTINATION include/JXXRS COMPONENT dev)
