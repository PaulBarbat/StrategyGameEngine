#pragma once
#include <string>
#include <memory>

class IComponent{
private:
    uint16_t ID;
public: 
    virtual ~IComponent() = default;
    virtual std::string toString() = 0;
};