/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  event_listener.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-01-18
  @ description:  offer function to create event listener, etc.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_EVENT_LISTENER_H_
#define CITY_HUNTER_SRC_EVENT_LISTENER_H_

#include <functional>
#include <string>
//#include "command_listener.h"
#include "listener.h"

namespace gamer 
{

class Command;
class Event;

class EventListener : public Listener 
{
public:
    typedef std::function<void(Event*)> EventCallback;

	virtual	~EventListener();

    // use for c++ only.
	static EventListener* create(int event_id, 
                                 const EventCallback& event_callback, 
                                 const std::string& listener_name, 
                                 int priority);

    // use for lua only.
    static EventListener* create(int event_id, 
                                 LuaFunction event_callback, 
                                 const std::string& listener_name,
                                 int priority);

    virtual void executeCallback(Event* event);

    virtual bool checkValidity() const override;

	inline int event_id() const { return target_id(); };

    inline void set_event_callback(const EventCallback& event_callback) 
    { 
        event_callback_ = event_callback; 
    };

	inline const EventCallback& event_callback() { return event_callback_; };
  
    inline bool is_registered() const { return is_registered_; };

private:
    // use for command listener
    typedef std::function<void(Command*)> CommandCallback;

    EventListener();

    // use for c++ only. use for command listener.
    static EventListener* createCmdListener(int event_id, 
                                 const CommandCallback& cmd_callback, 
                                 const std::string& listener_name, 
                                 int priority);

    // use for both c++ and lua.
    void init();

    // use for c++ only.
    bool init(int event_id, 
              const EventCallback& event_callback, 
              const std::string& listener_name, 
              int priority);

    // use for lua only.
    bool init(int event_id, 
              LuaFunction event_callback, 
              const std::string& listener_name, 
              int priority);

    // use for c++ only.use for command listener.
    bool init(int event_id, 
              const CommandCallback& cmd_callback, 
              const std::string& listener_name, 
              int priority);

    inline void set_registered(bool registered) { is_registered_ = registered; };

    EventCallback event_callback_;
    CommandCallback cmd_callback_;

    friend class CommandListener;
    friend class EventManager;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_EVENT_LISTENER_H_