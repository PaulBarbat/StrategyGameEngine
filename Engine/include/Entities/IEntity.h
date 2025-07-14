#pragma once
#include "IAtackable.h"
#include <utility>

class IEntity: public IAtackable{
protected:
    std::pair<int,int> location;
    uint16_t damage;
    uint16_t level_multiplier;
public:
    virtual ~IEntity()=default;
    virtual bool atack(const std::shared_ptr<IAtackable>& other) = 0;
    virtual bool move() = 0;
    virtual std::string toString() = 0;
};