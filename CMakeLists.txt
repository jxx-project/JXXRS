#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

cmake_minimum_required(VERSION 3.0)
project(JXXRS VERSION 0.1.0 LANGUAGES CXX)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

if(NOT Poco_INCLUDE_DIRS OR NOT Poco_LIBRARIES)
	find_package(Poco COMPONENTS Crypto Net NetSSL Util JSON XML REQUIRED)
endif()

find_package(JXXON REQUIRED)
find_package(Polymorphic REQUIRED)

file(GLOB JXXRS_SRCS_G src/JXXRS/*.cpp src/JXXRS/Accessor/*.cpp src/JXXRS/PocoImpl/*.cpp)
add_library(jxxrs ${JXXRS_SRCS_G})

target_include_directories(jxxrs PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/PocoImpl>
	$<BUILD_INTERFACE:${Poco_INCLUDE_DIRS}>
        $<INSTALL_INTERFACE:include>)
target_link_libraries(jxxrs ${Poco_LIBRARIES} ssl crypto)

install(TARGETS jxxrs EXPORT JXXRSConfig
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.h")
install(EXPORT JXXRSConfig DESTINATION share/JXXRS/cmake)
export(TARGETS jxxrs FILE JXXRSConfig.cmake)

enable_testing()

# On demand build of tests. See https://cmake.org/Wiki/CMakeEmulateMakeCheck
if(NOT "${CMAKE_GENERATOR}" MATCHES "Visual Studio")
	add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process)
else()
	add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process -C $(Configuration))
endif()

add_subdirectory(test EXCLUDE_FROM_ALL)

add_test(NAME ClientBuilderTest COMMAND clientBuilderTest)
add_dependencies(check clientBuilderTest)
