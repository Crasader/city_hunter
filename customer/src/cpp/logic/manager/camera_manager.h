/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  camera_manager.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-11-01
  @ description:  camera manager.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_CAMERA_MANAGER_H_
#define CITY_HUNTER_SRC_CAMERA_MANAGER_H_

namespace cocos2d
{
class Camera;
}

namespace gamer
{

class Command;

class CameraManager
{
public:
    ~CameraManager();

    static CameraManager* getInstance();

    static void destoryInstance();    

    bool init();

    cocos2d::Camera* camera() const;

private:
    CameraManager();    

    bool initListeners();

    void initCamera();

    void onCommandInitCamera(gamer::Command* cmd);

    static CameraManager* s_camera_manager_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_CAMERA_MANAGER_H_