/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  id_provider.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-04-01
  @ description:  provide object id.
  @ others:  
  @ history: 
    1.date:
      author:
      modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_OBJ_ID_PROVIDER_H_
#define CITY_HUNTER_SRC_OBJ_ID_PROVIDER_H_

namespace gamer 
{

class IDProvider 
{
public:
    static int getNextID() 
    { 
        static int s_id_ = 0; 
        s_id_++; 
        return s_id_; 
    }
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_OBJ_ID_PROVIDER_H_