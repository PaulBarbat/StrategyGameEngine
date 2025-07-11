#pragma once
#include "IAtackable.h"

class IEntity{
private:
    uint16_t damage;
    uint16_t level_multiplier;
public:
    virtual ~IEntity()=default;
    virtual bool atack() = 0;
    virtual bool move() = 0;
    virtual bool takeDamage(const int16_t& damage) = 0;
    virtual void toString() = 0;
};