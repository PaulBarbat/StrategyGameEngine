#pragma once

#include <memory>

class IAtackable{
private:
    uint16_t ID;
    int16_t health;
public:
    virtual ~IAtackable() = 0;
    virtual void takeDamage(const uint16_t& damage);
};