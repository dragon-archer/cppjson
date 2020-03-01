##################################################
# This file is published under the MIT License
#
# Copyright (C) 2019-2020 dragon-archer
#
# @file     CMakeLists.txt
# @brief    The CMake configure file
# @version  v0.0.1
# @author   dragon-archer
##################################################

cmake_minimum_required(VERSION 3.16) # for target_precompiled_headers
project(cppjson
		VERSION 0.0.1
		DESCRIPTION "A json parser for C++"
		LANGUAGES CXX)

aux_source_directory(src SRC_DIR)
set(SRC ${SRC_DIR})

add_library(cppjson SHARED ${SRC})
target_include_directories(cppjson PUBLIC include)
target_precompile_headers(cppjson PRIVATE include/pch.h)
# Set C++ standard to ISO C++ 14
target_compile_options(cppjson PRIVATE
					   $<$<CXX_COMPILER_ID:GNU,Clang>:-std=c++14>
					   $<$<CXX_COMPILER_ID:MSVC>:/std:c++14>)

# Build options
option(USE_UNORDERED_MAP "Use std::unordered_map instead of std::map" ON)
target_compile_definitions(cppjson PRIVATE $<$<BOOL:USE_UNORDERED_MAP>:CPPJSON_USE_UNORDERED_MAP>)

