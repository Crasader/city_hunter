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

#include <string>
#include <sstream>

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

//static std::string int_to_string(int n)
//{
//	const int size = 16;
//	char buf[size];
//	int ret = sprintf_s(buf, "%d", n);
//	if (ret > size)
//	{
//		buf[size - 1] = 0;
//	}
//	return std::string(buf);
//}

template <typename T>
std::string to_string(T value)
{
	std::ostringstream os;
	os << value;
	return os.str();
}

} // namespace utils

} // namespace gamer

#endif // CITY_HUNTER_SRC_UTILS_H_