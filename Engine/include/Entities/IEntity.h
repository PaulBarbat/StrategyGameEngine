#pragma once
#include "IAtackable.h"

class IEntity: public IAtackable{
protected:
    uint16_t damage;
    uint16_t level_multiplier;
public:
    virtual ~IEntity()=default;
    virtual bool atack(const std::shared_ptr<IAtackable>& other) = 0;
    virtual bool move() = 0;
    virtual void toString() = 0;
};