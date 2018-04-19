#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:	BSL-1.0
#

file(GLOB Mock_SRCS_G Mock/*.cpp Model/*.cpp)
add_library(Mock ${Mock_SRCS_G})
target_include_directories(Mock PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(Mock ${PROJECT_NAME}::Client)

add_executable(clientBuilderTest clientBuilderTest.cpp)
target_include_directories(clientBuilderTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(clientBuilderTest
	Mock
	${PROJECT_NAME}::Client)

add_executable(clientTest clientTest.cpp)
target_include_directories(clientTest PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_link_libraries(clientTest
	Mock
	${PROJECT_NAME}::Client)
