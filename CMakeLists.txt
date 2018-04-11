#
# Copyright (C) 2018 Dr. Michael Steffens
#
# SPDX-License-Identifier:     BSL-1.0
#

cmake_minimum_required(VERSION 3.0)
project(JXXRS VERSION 0.1.0 LANGUAGES CXX)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(JXXON REQUIRED CONFIG)
find_package(Poco COMPONENTS Net NetSSL REQUIRED CONFIG)

file(GLOB JXXRS_SRCS_G src/JXXRS/*.cpp src/JXXRS/Accessor/*.cpp src/JXXRS/PocoImpl/*.cpp)
add_library(JXXRS ${JXXRS_SRCS_G})
add_library(${PROJECT_NAME}::JXXRS ALIAS JXXRS)
set_target_properties(JXXRS PROPERTIES OUTPUT_NAME jxxrs)

target_include_directories(JXXRS PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/PocoImpl>
	$<BUILD_INTERFACE:${Poco_INCLUDE_DIRS}>
        $<INSTALL_INTERFACE:include>)
target_link_libraries(JXXRS JXXON::JXXON Poco::Net Poco::NetSSL)

install(TARGETS JXXRS EXPORT JXXRSTargets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.h")
install(EXPORT JXXRSTargets NAMESPACE ${PROJECT_NAME}:: DESTINATION share/JXXRS/cmake)
configure_file(cmake/JXXRSConfig.cmake.in JXXRSConfig.cmake @ONLY)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/JXXRSConfigVersion.cmake COMPATIBILITY SameMajorVersion)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/JXXRSConfig.cmake
	${CMAKE_CURRENT_BINARY_DIR}/JXXRSConfigVersion.cmake
	DESTINATION share/JXXRS/cmake)

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
