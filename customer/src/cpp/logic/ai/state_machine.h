/*******************************************************************************
 @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
 @ filename:	  state_machine.h
 @ author:		  Connor
 @ version:	      1.0.0
 @ date:		  2014-09-12
 @ description:   role state machine.
 @ others:
 @ history:
 1.date:
 author:
 modification:
 ********************************************************************************/

#ifndef CITY_HUNTER_SRC_STATE_MACHINE_H_
#define CITY_HUNTER_SRC_STATE_MACHINE_H_

#include <map>
#include "actor_states.h"
#include "macros.h"
#include "state.h"

namespace gamer
{

template <typename Entity>
class FSM 
{
public:
    typedef State<Entity> State;

	FSM(Entity* owner) 
        :owner_(owner)
        ,current_state_(nullptr)
		,is_state_changing_(false)
        ,enabled_(true)
	{

	}

	virtual ~FSM() 
    {
        realease();
    }

	inline void update() 
    { 
		if ( (true == enabled_) &&
		     (nullptr != current_state_) && 
		     (false == is_state_changing_) ) 
        {
			current_state_->onUpdate(owner_);
		}
	}

    // it will create state if the state has not created, then change to state
    // @ param state_id : constant form enum gamer::StateIDs
    void changeState(int state_id)
    {
        auto state = getState(state_id);
        if (nullptr == state)
        {
            state = createState((gamer::StateIDs)state_id);
        }

        changeState(state);
    }

    inline State* current_state() const { return current_state_; }

    inline int current_state_id() const 
    { 
        if (nullptr != current_state_)
        {
            return current_state_->id();
        }
        return StateIDs::INVALID_STATE; 
    }

	inline void set_enabled(bool enabled) { enabled_ = enabled; }

    inline const void enabled() const { return enabled_; }

    inline void set_owner(Entity* ent) { owner_ = ent; }

    inline Entity* owner(Entity* ent) const { return owner_; }

private:
    State* createState(gamer::StateIDs state_id)
    {
        switch (state_id)
        {
        case gamer::StateIDs::ATTACKING_STATE:
            {
                return new AttackingState<ActorType >(state_id); 
            }
            break;
        case gamer::StateIDs::FINDING_TARGET_STATE:
            {
                return new FindingTargetState<ActorType >(state_id); 
            }
            break;
        case gamer::StateIDs::IDLE_STATE:
            {
                return new IdleState<ActorType >(state_id); 
            }
            break;
        case gamer::StateIDs::NEARING_STATE:
            {
                return new NearingState<ActorType >(state_id); 
            }
            break;
        case gamer::StateIDs::BEING_ATTACKED_STATE:
            {
                return new BeingAttackedState<ActorType >(state_id); 
            }
            break;
        case gamer::StateIDs::DEAD_STATE:
            {
                return new DeadState<ActorType >(state_id); 
            }
            break;
        default:
            break;
        }

        return nullptr;
    }

    // change state if current state is not the input state, then store the state
    void changeState(State* state)
    {
        if (nullptr == state)
            return;

        is_state_changing_ = true;

        //assert(state && "<FSM::ChangeState>: trying to change to NULL state");

        // keep a record of the previous state
        // m_pPreviousState = current_state_;

        if (true == isInState(state))
        {
            is_state_changing_ = false;
            return;
        }

        // call the exit method of the existing state
        if (nullptr != current_state_)
        {
            current_state_->onExit(owner_);
        }

        // store the state
        addState(state);

        // change state to the new state
        current_state_ = state;

        // call the entry method of the new state
        current_state_->onEnter(owner_);

        is_state_changing_ = false;
    }

    void addState(State* state)
    {
        if (nullptr == state)
            return;

        auto it = states_map_.find(state->id());
        if (states_map_.end() != it)
        {
            states_map_.insert(std::make_pair(state->id(), state));
        }
    }

    State* getState(int state_id)  
    { 
        auto it = states_map_.find(state_id);
        if (states_map_.end() != it)
        {
            return (*it).second;
        }
        return nullptr;
    }

    inline const bool isInState(const State* state) const 
    {
        if (nullptr == state || nullptr == current_state_)
            return false;

        return current_state_->id() == state->id();
    }

    void realease()
    {
        std::for_each(states_map_.begin(), 
            states_map_.end(), 
            [&](std::pair<int, State*> a)
        { 
            SAFE_DELETE(a.second);
        });
    }

	Entity* owner_;
	State* current_state_;
    std::map<int, State*> states_map_;
	bool is_state_changing_;
	bool enabled_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_STATE_MACHINE_H_