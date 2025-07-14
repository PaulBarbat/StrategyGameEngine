#pragma once

#include "IMap.h"
//I made this factory more for exercise than anything else, Maps are not created that often to warant this factory

class MapFactory{
public:
    std::shared_ptr<IMap> createMap(std::string map_name);
};
