#include <Actor.h>
#include <Utils.h>
#include <iostream>

/*    Race m_race;
    uint16_t m_speed;
    bool m_isHostile;
    /*std::vector<Ability> abilities*/
    // std::pair<int,int> location;
    // uint16_t damage;
    // uint16_t level_multiplier;
    // uint16_t ID;
    // int16_t health;*/

Actor::Actor(Race race,
            uint16_t speed, 
            bool hostile, 
            /*std::vector<Ability> abilities,*/ 
            std::pair<int,int> location, 
            uint16_t damage,
            uint16_t level,
            int16_t health):m_race(race),
                            m_speed(speed),
                            m_isHostile(hostile)
{
    m_location=location;
    m_damage = damage;
    m_level_multiplier = level;
    m_health = health;
    m_ID = Utils::getID();
}
/*
Actor::Actor(const Actor& other){

}

Actor& Actor::operator=(const Actor& other){

}

Actor::Actor(Actor&& other){

}

Actor& Actor::operator=(Actor&& other){

}*/

void Actor::takeDamage(const uint16_t& damage){
    m_health = (m_health - damage < 0)? 0 : m_health - damage;
}

uint16_t Actor::getID()const{
    return m_ID;
}

bool Actor::atack(const std::shared_ptr<IAtackable>& other){
    other->takeDamage(m_damage*m_level_multiplier);//TODO tweek scaling, it should scale but not just multiply with the level
    return true;
}

bool Actor::move(std::pair<int,int> new_location){
    m_location=std::make_pair(new_location.first, new_location.second);
    return true;
}

std::string Actor::toString(){
    return ("Actor -> ID: "+ std::to_string(m_ID)+
        "Type: "+animalTypeToString(m_type)+
        "Level: " +std::to_string(m_level_multiplier)+
        "Health: "+std::to_string(m_health)+
        "Damage: "+std::to_string(m_damage));
}
