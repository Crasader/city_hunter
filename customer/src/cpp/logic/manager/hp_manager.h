/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  hp_manager.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-04-05
  @ description:  hp calumniating, hp effect dealing, etc.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_HP_MANAGER_H_
#define CITY_HUNTER_SRC_HP_MANAGER_H_

namespace gamer
{

class Command;

class HPManager
{
public:
    ~HPManager();

    static HPManager* getInstance();

    static void destoryInstance();

    bool init();

private:
    HPManager();

    bool initListeners();

    void onCommandAttack(gamer::Command* cmd);
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_HP_MANAGER_H_