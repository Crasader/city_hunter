/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  data_manager.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-11-09
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "data_manager.h"

#include <fstream>

#include "macros.h"
#include "cocos2d.h"

namespace gamer
{

DataManager::DataManager()
    :is_init_ok_(false)
{

}

DataManager::~DataManager()
{

}

DataManager* DataManager::getInstance()
{
    static DataManager* data_manager = nullptr;
    if (nullptr == data_manager)
    {
        data_manager = new DataManager();
        if ( !data_manager->init() )
        {
            SAFE_DELETE(data_manager); 
        }
    }
    return data_manager;
}

bool DataManager::init()
{
    if ( !is_init_ok_ )
    {
        GOOGLE_PROTOBUF_VERIFY_VERSION;  

        dir_cfg_ = cocos2d::FileUtils::getInstance()->getWritablePath();
        actor_cfg_path_ = dir_cfg_ + "res\\cfg\\actor_cfg.pb";

        std::fstream input(actor_cfg_path_.c_str(), std::ios::in | std::ios::binary);
        if (!actor_cfg_.ParseFromIstream(&input)) 
        {        
            assert("readActorCfg failed !");
        }
        is_init_ok_ = true;
    }
    return true;
}

} // namespace gamer 