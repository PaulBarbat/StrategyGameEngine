#pragma once

#include "IEntity.h"

class Animal:public IEntity{
public:
    Animal(const int16_t& health ,const uint16_t& damage);
    bool atack();
    bool move();
    bool takeDamage(const int16_t& damage);
    void toString();
};