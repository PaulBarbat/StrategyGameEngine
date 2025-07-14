#include "MapFactory.h"
#include <string>
#include <nlohmann/json.hpp>

using json = nlohman::json;

std::shared_ptr<IMap> MapFactory::createMap(std::string map_name){
    std::ifstream file("resources/maps.json");
    if(!file){
        std::cerr << "Could not open file: resources/maps.json" <<std::endl;
        return;
    }

    json j;
    file >> j;

    for(const auto& element: j)
    {
        if(element.contains("name") && element["name"] == map_name){
            if(element.contains("data"))
                return element["data"];
        }
    }

    throw std::runtime_error("Map name not found: " + map_name);
}