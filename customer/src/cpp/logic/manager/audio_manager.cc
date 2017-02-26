/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  audio_manager.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2016-11-05
 @ description:   see the header file.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#include "audio_manager.h"
#include "macros.h"

namespace gamer
{

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{

}

AudioManager* AudioManager::getInstance()
{
    static AudioManager* audio_manager = nullptr;
    if (nullptr == audio_manager)
    {
        audio_manager = new AudioManager();
        if ( !audio_manager->init() )
        {
            SAFE_DELETE(audio_manager); 
        }
    }
    return audio_manager;
}

void AudioManager::destoryInstance()
{
    AudioManager* manager = AudioManager::getInstance();
    SAFE_DELETE(manager);
}

bool AudioManager::init()
{
    return true;
}

} // namespace gamer