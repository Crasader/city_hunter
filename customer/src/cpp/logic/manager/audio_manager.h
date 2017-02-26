/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  audio_manager.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2016-11-05
 @ description:   audio manager.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#ifndef CITY_HUNTER_SRC_AUDIO_MANAGER_H_
#define CITY_HUNTER_SRC_AUDIO_MANAGER_H_

namespace gamer
{

class AudioManager
{
public:
    ~AudioManager();

    static AudioManager* getInstance();

    static void destoryInstance();

    bool init();

private:
    AudioManager();
}; 

} // namespace gamer

#endif // CITY_HUNTER_SRC_AUDIO_MANAGER_H_