#pragma once
#include <memory>
#include <nlohmann/json.hpp>
#include "Animal.h"

using json = nlohmann::json;

class AnimalFactory{
private:
    static json loadAnimalData();
    static std::string animalTypeToString(AnimalType type);
public:
    static std::unique_ptr<Animal> createAnimal(AnimalType type,std::pair<int,int> location);
};