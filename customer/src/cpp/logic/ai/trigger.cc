#include "trigger.h"

#include "macros.h"
//#include "platform/platform.h"

namespace gamer {

Trigger::Trigger()
{

}

Trigger::~Trigger()
{

}

int Trigger::registerTrigger(TriggerRecord* trigger_record)
{
    if ( nullptr == trigger_record )
        return 0;
    trigger_map_.insert(TriggerMap::value_type(trigger_record->trigger_id, 
                                                trigger_record));
    return trigger_record->trigger_id;
}

void Trigger::removeTrigger(int trigger_id)
{
	TriggerMap::iterator it = trigger_map_.begin();
	while (trigger_map_.end() != it)
	{
		if(it->second->trigger_id == trigger_id)
		{
			SAFE_DELETE(it->second);
			trigger_map_.erase(it);
			return;
		}
		++it;
	}
}

void Trigger::update()
{
    /*
	Role* role = nullptr;
	TriggerRecord* trigger_record = nullptr;
	TriggerMap::iterator it = trigger_map_.begin();

	//timeval t;
	//cocos2d::gettimeofday(&t, 0);
    //gettimeofday(&t, 0);
	//long nCurTime = t.tv_sec;
    
    // TODO : get system time for cross platform
    timeval t;
    getTimeOfDay(&t);
    long nCurTime = t.tv_sec;

	while (trigger_map_.end() != it)
	{
		trigger_record = it->second;
		if(nullptr != trigger_record)
		{
			if( (0 != trigger_record->duration) && 
				(nCurTime > trigger_record->duration) )
			{
				SAFE_DELETE(trigger_record);
				it = trigger_map_.erase(it);
			}
			else
			{
				if(true == trigger_record->is_dynamic_source)
				{
					trigger_record->time_stamp = nCurTime;
					// TODO : update position
				}
				++it;
			}
		}
		else
		{
			++it;
		}
	}

	// trig AI
    //typedef std::map<long, Role*> RoleMap;
    RoleMap::iterator iter = gamer::g_role_map_.begin();
	for (; iter != g_role_map_.end(); ++iter)
	{
		role = iter->second;
		if ( nullptr == role )
			continue;
		// if AI need trig
		if ( (0 == role->getTriggerExpirationTime()) || 
             (nCurTime <= role->getTriggerExpirationTime()) )
		{
			for (it = trigger_map_.begin(); it != trigger_map_.end(); ++it)
			{
				trigger_record = it->second;
				// check ID
				if ( trigger_record->source_id == role->id() )
					continue;
				// check radius
                cocos2d::Point role_pos = role->getPosition();
                cocos2d::Point trigger_pos = trigger_record->position;
				if (trigger_record->radius < role_pos.getDistance(trigger_pos))
					continue;
				// check trigger type
				if ( !(trigger_record->trigger_type & role->getTriggeType()) )
					continue;

				// AI handle trigger
				if ( role->handleTrigger(trigger_record) )
				{
					trigger_record->dircetion = role->getPositionX() > 
                        trigger_record->position.x ? -1 : 1;
					break;
				}

				++it;
			}
		}
	}
    */
}

void Trigger::setTriggerPosition(int trigger_id, 
                                 const cocos2d::Point& position)
{
	TriggerMap::iterator it = trigger_map_.begin();
	while (trigger_map_.end() != it)
	{
		if(it->second->trigger_id == trigger_id)
		{
			if(it->second->position != position)
				it->second->position = position;
			return;
		}
		++it;
	}
}

cocos2d::Point Trigger::getTriggerPosition(int trigger_id)
{
	TriggerMap::iterator it = trigger_map_.begin();
	while (trigger_map_.end() != it)
	{
		if(it->second->trigger_id == trigger_id)
		{
			return it->second->position;
		}
		++it;
	}
	return cocos2d::Point::ZERO;
}

} // namespace gamer