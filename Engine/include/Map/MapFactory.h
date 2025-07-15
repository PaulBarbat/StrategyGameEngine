#pragma once
#include <vector>

#include "IMap.h"
//I made this factory more for exercise than anything else, Maps are not created that often to warant this factory

class MapFactory{
private:
    std::vector<std::shared_ptr<Tile>> parseMapData(const std::string& data)const;
public:
    std::shared_ptr<IMap> createMap(std::string map_name);
};
