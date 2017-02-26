/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  macros.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2014-09-12
 @ description:   define common macros.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#ifndef CITY_HUNTER_SRC_MACROS_H_
#define CITY_HUNTER_SRC_MACROS_H_

namespace gamer 
{

#define GAMER_PLATFORM_UNKNOWN			0
#define GAMER_PLATFORM_IOS				1
#define GAMER_PLATFORM_ANDROID			2
#define GAMER_PLATFORM_WIN32			3

#define GAMER_PLATFORM    GAMER_PLATFORM_WIN32

#define NS_GAMER_BEGIN					namespace gamer {
#define NS_GAMER_END					}
#define USING_NS_GAMER					using namespace gamer

#define SAFE_DELETE(p)					do { if(nullptr != (p)) { delete (p); (p) = nullptr; } } while(0)

#define CALLBACK_SELECTOR_0(__selector__,__target__, ...) std::bind(&__selector__,__target__, ##__VA_ARGS__)
#define CALLBACK_SELECTOR_1(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, ##__VA_ARGS__)
#define CALLBACK_SELECTOR_2(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, std::placeholders::_2, ##__VA_ARGS__)
#define CALLBACK_SELECTOR_3(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, ##__VA_ARGS__)

} // namespace gamer

#endif // CITY_HUNTER_SRC_MACROS_H_
