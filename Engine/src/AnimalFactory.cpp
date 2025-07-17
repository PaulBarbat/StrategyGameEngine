#include "AnimalFactory.h"
#include <fstream>
#include <iostream>

static json AnimalFactory::loadAnimalData(){
    std::ifstream file("resources/animals.json");

    if(!file){
        std::cerr<<"Could not open file resources/animals.json"<<std::endl;
        return nullptr;
    }

    json j;
    file >> j;
    return j;
}

static std::unique_ptr<Animal> AnimalFactory::createAnimal(AnimalType type,std::pair<int,int> location){
    static json animalData=AnimalFactory::loadAnimalData();
    if(json==nullptr){
        throw std::runtime_error("Could not read json for animals");
    }

    for(const auto& element: j)
    {
        if(element.contains("name") && (element["name"] == Animal::animalTypeToString(type)))
        {
            return std::make_unique<Animal>(element["health"], element["damage"], location, type);
        }
    }
    return nullptr;
}