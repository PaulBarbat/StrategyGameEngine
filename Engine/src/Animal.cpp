#include "Animal.h"
#include "Utils.h"

Animal::Animal(const int16_t& health ,const uint16_t& damage){
    this->ID=Utils::getID();
    this->damage=damage;
    this->level_multiplier=1;
    this->health=health;
}

bool Animal::atack(const std::shared_ptr<IAtackable>& other){
    other->takeDamage(this->damage*this->level_multiplier);//TODO tweek scaling, it should scale but not just multiply with the level
    return true;
}

bool Animal::move(){

}

bool Animal::takeDamage(const int16_t& damage){

}

void Animal::toString(){

}