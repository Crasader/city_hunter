/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  utils.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2014-09-10
  @ description:  offer common functions.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_UTILS_H_
#define CITY_HUNTER_SRC_UTILS_H_

#include "macros.h"

namespace gamer
{

namespace utils 
{

// use for deleting std::vector object in std::for_each.
struct delete_vector_obj
{
    template <typename T>
    void operator() (const T* ptr) const
    {
        SAFE_DELETE(ptr);
    }
};

// use for deleting std::map object in std::for_each.
struct delete_map_obj
{
    template <typename T1, typename T2>
    void operator() (const T1, const T2* ptr) const
    {
        SAFE_DELETE(ptr);
    }
};

} // namespace utils

} // namespace gamer

#endif // CITY_HUNTER_SRC_UTILS_H_