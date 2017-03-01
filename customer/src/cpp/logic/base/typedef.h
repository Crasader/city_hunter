/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  typedef.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2015-11-01
 @ description:   define data type for cross platform.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#ifndef CITY_HUNTER_SRC_TYPEDEF_H_
#define CITY_HUNTER_SRC_TYPEDEF_H_

#include "macros.h"

namespace gamer 
{
/*
typedef signed char		int8;
typedef signed short	int16;
typedef signed int		int32;
typedef unsigned char	uint8;
typedef unsigned short	uint16;
typedef unsigned int	uint32;
typedef float			float32;
typedef double			float64;
typedef unsigned long	ulong;
*/

typedef unsigned int uint;

#if GAMER_PLATFORM == GAMER_PLATFORM_WIN32
//    typedef __int8  int8;
//    typedef __int16 int16;
//    typedef __int32 int32;
//    typedef __int64 int64;
//
//    typedef unsigned __int8  uint8;
//    typedef unsigned __int16 uint16;
//    typedef unsigned __int32 uint32;
//    typedef unsigned __int64 uint64;
//#else
//    typedef int8_t  int8;
//    typedef int16_t int16;
//    typedef int32_t int32;
//    typedef int64_t int64;
//
//    typedef uint8_t  uint8;
//    typedef uint16_t uint16;
//    typedef uint32_t uint32;
//    typedef uint64_t uint64;
#endif

#ifdef GAMER_TARGET_IOS

#endif // GAMER_TARGET_IOS

#ifdef GAMER_TARGET_ANDROID

#endif // GAMER_TARGET_ANDROID

#ifdef GAMER_TARGET_WIN32

#endif // GAMER_TARGET_WIN32

} // namespace gamer

#endif // CITY_HUNTER_SRC_TYPEDEF_H_