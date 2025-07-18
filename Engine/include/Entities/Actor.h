#pragma once
#include "IEntity.h"

enum class Race{
    Human,
    Elf,
    Dwarf,
    Orc
};

class Actor: public IEntity{
private:
    Race m_race;
    uint16_t m_speed;
    bool m_isHostile;
    /*std::vector<Ability> abilities*/
    // std::pair<int,int> location;
    // uint16_t damage;
    // uint16_t level_multiplier;
    // uint16_t ID;
    // int16_t health;
public:
    ~Actor()=default;
    Actor(Race race);
    Actor(const Actor& other);
    Actor& operator=(const Actor& other);
    Actor(Actor&& other);
    Actor& operator=(Actor&& other);
    void takeDamage(const uint16_t& damage);
    uint16_t getID()const;
    bool atack(const std::shared_ptr<IAtackable>& other);
    bool move();
    std::string toString();
};