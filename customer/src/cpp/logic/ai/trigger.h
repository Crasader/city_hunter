#ifndef CITY_HUNTER_SRC_TRIGGER_H_
#define CITY_HUNTER_SRC_TRIGGER_H_

#include "cocos2d.h"

#include "typedef.h"

namespace gamer {

enum TriggerTypes
{
	NONE		=	0,
	ENEMY_NEAR	=	1,
	ENEMY_LEAVE	=	2,
	GUN_FIRE	=	4,
	EXPLOSION	=	8
};

struct TriggerRecord 
{
	TriggerRecord(TriggerTypes trigger_type, 
                  int trigger_id, 
                  int priority, 
                  int source_id, 
                  const cocos2d::Point& position, 
                  float radius, 
                  float duration, 
                  bool is_dynamic_source)
	{
		 this->trigger_type	     =  trigger_type;
		 this->trigger_id		 =  trigger_id;
		 this->source_id		 =  source_id;
		 this->position		     =  position;
		 this->radius		     =  radius;
		 //nTimeStamp
		 this->duration	         =  duration;
		 this->is_dynamic_source =  is_dynamic_source;
	}

	TriggerTypes trigger_type;
	int trigger_id;
	int source_id;
	cocos2d::Point position;
	float radius;
    float dircetion; // fDircetion < 0 : trigger is come from left;fDircetion > 0 : trigger is come from right.
	long duration;			
	int time_stamp;
	bool is_dynamic_source;
};

// default sort method is 'less', use 'greater' to make the trigger response 
// first if the priority of it is greater.
typedef std::multimap<int, TriggerRecord*, 
    std::greater<unsigned short>> TriggerMap;

class Trigger {
  public:
	Trigger();
	~Trigger();

    int registerTrigger(TriggerRecord* trigger_record);

	void removeTrigger(int trigger_id);

	void update();

	void setTriggerPosition(int trigger_id, const cocos2d::Point& position);

    cocos2d::Point getTriggerPosition(int trigger_id);

  private:
	TriggerMap trigger_map_;
}; 

} // namespace gamer

#endif // CITY_HUNTER_SRC_TRIGGER_H_
