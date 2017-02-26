/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  camera_manager.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-11-01
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "camera_manager.h"

#include <cassert>

#include "cocos2d.h"

#include "command.h"
#include "command_constants.h"
#include "command_listener.h"
#include "command_manager.h"
#include "macros.h"
#include "scene_manager.h"

namespace gamer
{

CameraManager* CameraManager::s_camera_manager_ = nullptr;

CameraManager::CameraManager()
{

}

CameraManager::~CameraManager()
{

}

CameraManager* CameraManager::getInstance()
{
    if (nullptr == s_camera_manager_)
    {
        s_camera_manager_ = new CameraManager();
        if( !s_camera_manager_->initListeners() )
        {
            SAFE_DELETE(s_camera_manager_);
        }
    }
    return s_camera_manager_;
}

void CameraManager::destoryInstance()
{
    SAFE_DELETE(s_camera_manager_);
}

bool CameraManager::init()
{
    return true;
}

bool CameraManager::initListeners()
{
    auto listener = gamer::CommandListener::create(
        CommandIDs::CMD_ID_INIT_CAMERA, 
        CALLBACK_SELECTOR_1(CameraManager::onCommandInitCamera, this),
        "CameraManager::onCommandInitCamera", 
        1);
    CommandManager::getInstance()->addCmdListener(listener);

    return true;
}

void CameraManager::initCamera()
{
    auto scene = SceneManager::getInstance()->cur_scene();
    if (nullptr != scene)
    {
        auto default_camera = scene->getDefaultCamera();

        default_camera->setGlobalZOrder(10000);

        //default_camera->setPosition3D(cocos2d::Vec3(0, 130, 130));
        default_camera->setPosition3D(cocos2d::Vec3(0, 130, 180));
        default_camera->lookAt(cocos2d::Vec3::ZERO);
    }
}

void CameraManager::onCommandInitCamera(gamer::Command* cmd)
{
    initCamera();
}

} // namespace gamer