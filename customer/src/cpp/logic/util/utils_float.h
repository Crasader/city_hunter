/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  utils_float.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-09-21
  @ description:  offer some common functions about float and double.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_UTILS_FLOAT_H_
#define CITY_HUNTER_SRC_UTILS_FLOAT_H_

namespace gamer
{

namespace utils_float 
{

static const float EPSINON = 0.00001f;

bool float_equal(float a, float b)
{
    if (((a - b) >= - EPSINON) && ((a - b) <= EPSINON))
        return true;
    return false;
}

} // namespace utils_float

} // namespace gamer

#endif // CITY_HUNTER_SRC_UTILS_FLOAT_H_