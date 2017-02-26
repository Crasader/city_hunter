/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  state.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2015-09-07
 @ description:   actor state base class.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#ifndef CITY_HUNTER_SRC_STATE_H_
#define CITY_HUNTER_SRC_STATE_H_

namespace gamer
{

template <class Entity>
class State 
{
public:
    State(int id) : id_(id) {}

	virtual ~State() {}

	virtual void onEnter(Entity* entity) = 0;

	virtual void onUpdate(Entity* entity) = 0;

	virtual void onExit(Entity* entity) = 0;

    inline int id() const { return id_; }

    inline void set_id(int id) { id_ = id; }

private:   
    int id_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_STATE_H_
