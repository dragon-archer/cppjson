/**
 * @file    include/pch.h
 * @author  dragon-archer <dragon-archer@outlook.com>
 * @brief   This is the precompiled header for cppjson
 * @version 0.0.1
 * 
 * @license This file is published under the MIT License
 *          Copyright (C) 2020 dragon-archer
 */

#ifndef _CPPJSON_PCH_H
#define _CPPJSON_PCH_H 1

/**
 * @brief   Check for C++ standard, must be higher than C++11
 */
#ifndef __cplusplus
#error "The cppjson must be compiled in C++ mode"
#endif /* __cplusplus */

#if __cplusplus < 201402L /* Not C++14 ? */
#  if __cplusplus == 201103L /* Is C++11 ? */
#    pragma message("It is suggeseted to compile cppjson under C++14, not C++11")
#  else
#    ifndef _MSC_VER /* Not MSVC => Is C++98 or lower */
#      error("The cppjson must be compiled under C++11 or higher")
#    else /* MSVC */
#      if (_MSC_VER < 1900) /* Lower than VS15 */ || (_MSVC_LANG < 201402L) /* Not C++14 */
#        error("The cppjson must be compiled under VS15 update 3 or higher")
#      endif
#    endif
#  endif
#endif

/**
 * @brief   Include standard headers
 */
#include <cstddef> /* for std::int64_t as json integer */
#include <string> /* for std::string as json string */
#include <vector> /* for std::vector as json array */
#include <memory> /* for std::unique_ptr */
#ifdef CPPJSON_USE_UNORDERED_MAP
#include <unordered_map> /* for std::unordered_map as json object */
#else
#include <map> /* for std::map as json object */
#endif /* defined(CPPJSON_USE_UNORDERED_MAP) */

#endif /* _CPPJSON_PCH_H */
