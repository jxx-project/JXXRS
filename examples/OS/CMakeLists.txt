#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

cmake_minimum_required(VERSION 3.0)
project(OS VERSION 0.1.0 LANGUAGES CXX)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

find_package(JXXRS REQUIRED)

file(GLOB API_SRCS_G API/src/OS/API/*.cpp API/src/OS/API/Model/*.cpp)
add_library(osapi ${API_SRCS_G})

target_include_directories(osapi PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/API/include>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/API/src>
	$<INSTALL_INTERFACE:include>)
target_link_libraries(osapi jxxrs)

file(GLOB Keystone_SRCS_G Keystone/src/OS/Keystone/V2/Model/*.cpp Keystone/src/OS/Keystone/V3/Model/*.cpp)
add_library(oskeystone ${Keystone_SRCS_G})

target_include_directories(oskeystone PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/Keystone/include>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/Keystone/src>
	$<INSTALL_INTERFACE:include>)
target_link_libraries(oskeystone osapi jxxrs)
