/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  action_manager.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2016-03-29
 @ description:   manage attack action, attack audio, hp, etc.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#ifndef CITY_HUNTER_SRC_ACTION_MANAGER_H_
#define CITY_HUNTER_SRC_ACTION_MANAGER_H_

namespace gamer
{

class Command;
class ActorCfg;

class ActionManager
{
public:
    ~ActionManager();

    static ActionManager* getInstance();

    static void destoryInstance();

    bool init();

private:
    ActionManager();

    bool initListeners();
    
    void onCommandReceived(gamer::Command* cmd); // TODO : all manager should has such a function

    void dealWithPlayActionCommand(gamer::Command* cmd);

    void dealWithAttackCommand(gamer::Command* cmd);
}; 

} // namespace gamer

#endif // CITY_HUNTER_SRC_ACTION_MANAGER_H_