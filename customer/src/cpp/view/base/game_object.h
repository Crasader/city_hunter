/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  game_object.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-04-21
  @ description:  base class of visual obj.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CITY_HUNTER_SRC_GAMEOBJECT_H_
#define CITY_HUNTER_SRC_GAMEOBJECT_H_

#include <map>
#include <string>

namespace gamer 
{

class GameObject
{
public:
    GameObject(int id) : id_(id) {}

	virtual ~GameObject() {}

    inline const int id() const { return id_; }

    inline void set_id(int id) { id_ = id; }

    bool addProperty(const std::string& property_name, float value)
    {
        if ( !isFloatPropertyExists(property_name) )
        {
            properties_float_[property_name] = value;
            return true;
        }
        return false;        
    }

    bool addProperty(const std::string& property_name, const std::string& value)
    {
        if ( !isStrPropertyExists(property_name) )
        {
            properties_str_[property_name] = value;
            return true;
        }
        return false; 
    }

    bool setPropertyValue(const std::string& property_name, float value)
    {
        properties_float_[property_name] = value;
        return true;
    }

    bool setPropertyValue(const std::string& property_name, const std::string& value)
    {
        properties_str_[property_name] = value;
        return true;
    }

    bool getPropertyValue(const std::string& property_name, float& value)
    {
        if ( !isFloatPropertyExists(property_name) )
        {
            value = properties_float_[property_name];
            return true;
        }
        return false; 
    }

    bool getPropertyValue(const std::string& property_name, std::string& value)
    {
        if ( !isStrPropertyExists(property_name) )
        {
            value = properties_str_[property_name];
            return true;
        }
        return false; 
    }

    bool isFloatPropertyExists(const std::string& property_name) const
    {
        return properties_float_.find(property_name) != properties_float_.end();
    }

    bool isStrPropertyExists(const std::string& property_name) const
    {
        return properties_str_.find(property_name) != properties_str_.end();
    }

private:
    int id_;

    std::map<std::string, float> properties_float_;
    std::map<std::string, std::string> properties_str_;
};

} // namespace gamer

#endif // CITY_HUNTER_SRC_GAMEOBJECT_H_