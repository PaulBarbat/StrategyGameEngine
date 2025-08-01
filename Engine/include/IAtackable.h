#pragma once

#include <memory>

class IAtackable{
protected:
    uint16_t m_ID;
    int16_t m_health;
public:
    virtual ~IAtackable() = 0;
    virtual void takeDamage(const uint16_t& damage) = 0;
    virtual uint16_t getID()const = 0;
};