#include "MapFactory.h"
#include "StartingMap.h"
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>  
#include <iostream>

using json = nlohmann::json;

std::vector<std::shared_ptr<Tile>> MapFactory::parseMapData(const std::string& data){
    std::istringstream iss(data);
    size_t value;
    iss >> value;

    std::vector<std::shared_ptr<Tile>> values;
    values.reserve(value*value);
    Terain t;

    while(iss>>value){
        switch(value){
            case 0: 
                t=Terain::Grass;
                break;
            case 1:
                t=Terain::Stone;
                break;
            case 2:
                t=Terain::Dirt;
                break;
            default:
                throw std::runtime_error("Invalid element in json data"+std::to_string(value));
        }
        values.push_back(std::make_shared<Tile>(Tile{true,std::nullopt, t}));
    }
    std::cout<<"In parse data: "<<std::endl;
    int size=static_cast<uint16_t>(std::sqrt(values.size()));
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            std::cout<<static_cast<int>(values.at(i*size+j).get()->terainType)<<" ";
        }
        std::cout<<std::endl;
    }
    return values;
}

std::shared_ptr<IMap> MapFactory::createMap(const std::string& map_name){
    std::ifstream file("resources/maps.json");
    if(!file){
        std::cerr << "Could not open file: resources/maps.json" <<std::endl;
        return nullptr;
    }

    json j;
    file >> j;

    for(const auto& element: j)
    {
        if(element.contains("name") && element["name"] == map_name){
            if(element.contains("data")){
                auto ret = std::make_shared<StartingMap>(std::move(parseMapData(element["data"])));
                std::cout<<"in createMap"<<std::endl;
                *ret->printMap();
                return ret;
            }
        }
    }

    throw std::runtime_error("Map name not found: " + map_name);
}