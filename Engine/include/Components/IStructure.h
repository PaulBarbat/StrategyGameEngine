#pragma once
#include "IComponent.h"
#include "IAtackable.h"
#include <vector>

class IStructure: public IAtackable{
private:
public:
    virtual ~IStructure() = default;
    virtual std::string toString() = 0;
    virtual std::vector<std::shared_ptr<IComponent>> destruct() = 0;
};