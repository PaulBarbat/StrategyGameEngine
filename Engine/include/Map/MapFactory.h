#pragma once
#include <vector>

#include "IMap.h"
//I made this factory more for exercise than anything else, Maps are not created that often to warant this factory

class MapFactory{
private:
    static std::vector<std::shared_ptr<Tile>> parseMapData(const std::string& data);
public:
    static std::shared_ptr<IMap> createMap(const std::string& map_name);
};
