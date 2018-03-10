#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

project(libJXXRS CXX)
cmake_minimum_required(VERSION 3.0)

set(JXXRS_MAJOR_VERSION 0)
set(JXXRS_MINOR_VERSION 1)
set(JXXRS_PATCH_VERSION 0)
set(JXXRS_VERSION ${JXXRS_MAJOR_VERSION}.${JXXRS_MINOR_VERSION}.${JXXRS_PATCH_VERSION})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Poco REQUIRED Net NetSSL)
include_directories(src ${Poco_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_subdirectory(src)
