/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  pb_creator.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-11-09
  @ description:  pb file creator.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_PB_CREATOR_H_
#define CITY_HUNTER_SRC_PB_CREATOR_H_

#include <string>

namespace gamer
{

class PBCreator
{
public:
    static void createMapCfg();

	static void createCameraCfg();

    static void createActorStateCfg();

    static void createModelCfg();

    static void createAudioCfg();

    static void createActionCfg();

    static const std::string dir_cfg;
};

} // namespace gamer 

#endif // CITY_HUNTER_SRC_PB_CREATOR_H_