#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

find_package(Threads)

file(GLOB MOCK_SRCS_G Mock/*.cpp Model/*.cpp)
add_library(mock ${MOCK_SRCS_G})
target_include_directories(mock PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(mock jxxrs jxxon)

add_executable(clientBuilderTest clientBuilderTest.cpp)
target_include_directories(clientBuilderTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(clientBuilderTest
	mock
	jxxrs
	jxxon
	${CMAKE_THREAD_LIBS_INIT})
