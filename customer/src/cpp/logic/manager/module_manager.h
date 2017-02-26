/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  module_manager.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2016-04-05
  @ description:  init game module, etc.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_MODULE_MANAGER_H_
#define CITY_HUNTER_SRC_MODULE_MANAGER_H_

namespace gamer
{

class ModuleManager
{
public:
    ~ModuleManager();

    static ModuleManager* getInstance();

    static void destoryInstance();

    void initAllModules();

private:
    ModuleManager();

    bool init();
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_MODULE_MANAGER_H_