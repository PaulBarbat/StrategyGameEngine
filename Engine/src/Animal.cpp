#include "Animal.h"
#include "Utils.h"
#include <iostream>

Animal::Animal(int16_t health ,uint16_t damage, std::pair<int,int> location, AnimalType type){
    m_ID=Utils::getID();
    m_damage=damage;
    m_level_multiplier=1;
    m_health=health;
    m_location=std::make_pair(location.first, location.second);
    m_type=type;

    this->random_values_size=10;
    if(this->random_values_size>0){
        random_values=new int*[random_values_size];//create the pointer array
        for(int i=0;i<this->random_values_size;++i){
            random_values[i] = new int[this->random_values_size]; // create each array
            for(int j=0; j<this->random_values_size;++j)
                this->random_values[i][j] = i*j;
        }
    }

    for(int i=0; i< 3; ++i)
        random_vector.emplace_back(std::make_shared<int>(i));

    random_unique_ptr= std::make_unique<int>(23);
    std::cout<<"Animal Constructor"<< std::endl;
}

Animal::~Animal(){
    for(int i=0; i<random_values_size; ++i)
        delete[] random_values[i]; //destroy each array first
    delete[] random_values; //delete the empty pointer array
    std::cout<<"Animal Destructor"<<std::endl;
}

Animal::Animal(const Animal& other){
    m_ID=other.m_ID;//we might want to generate another id
    m_health=other.m_health;
    m_damage=other.m_damage;
    m_level_multiplier=other.m_level_multiplier;
    m_location=std::make_pair(other.m_location.first, other.m_location.second);
    m_type=other.m_type;

    this->random_vector=other.random_vector;
    this->random_unique_ptr=(other.random_unique_ptr? std::make_unique<int>(*other.random_unique_ptr) : nullptr); //copy the value 
    random_values_size=other.random_values_size;
    random_values=new int*[random_values_size];//create the array of pointers
    for(int i=0; i< random_values_size; ++i)
    {
        random_values[i] = new int[random_values_size]; //create each array
        for(int j=0; j< random_values_size; ++j)
            random_values[i][j] = other.random_values[i][j];//copy the values
    }
}

Animal& Animal::operator=(const Animal& other){
    if(this == &other)
        return *this;
    m_ID=other.m_ID;//here we might want to generate another ID
    m_health=other.m_health;
    m_damage=other.m_damage;
    m_level_multiplier=other.m_level_multiplier;
    m_location=std::make_pair(other.m_location.first, other.m_location.second);
    m_type=other.m_type; 

    this->random_vector=other.random_vector;
    this->random_unique_ptr=(other.random_unique_ptr? std::make_unique<int>(*other.random_unique_ptr) : nullptr); //copy the value 

    //first we free up the raw pointers
    for(int i=0; i< random_values_size; ++i)
        delete[] random_values[i];//delete each array
    delete[] random_values;//delete the main pointer array

    random_values_size=other.random_values_size;//get the other size
    random_values=new int*[random_values_size];//create the array of pointers
    for(int i=0; i< random_values_size; ++i)
    {
        random_values[i] = new int[random_values_size]; //create each array
        for(int j=0; j< random_values_size; ++j)
            random_values[i][j] = other.random_values[i][j];//copy the values
    }
    return *this;
}

Animal::Animal(Animal&& other) noexcept
{
    m_ID=other.m_ID;//here we might want to generate another ID
    m_health=other.m_health;
    m_damage=other.m_damage;
    m_level_multiplier=other.m_level_multiplier;
    m_location=std::make_pair(other.m_location.first, other.m_location.second);
    m_type=other.m_type;

    random_values_size=other.random_values_size;

    random_vector = std::move(other.random_vector);
    random_unique_ptr = std::move(other.random_unique_ptr);

    random_values = other.random_values;//we basically just have to point to the same memory
    other.random_values = nullptr; //then assign nullptr, not destroy the memory address
    other.random_values_size = 0;
}

Animal& Animal::operator=(Animal&& other) noexcept{
    if(this == &other)
        return *this;
    m_ID=other.m_ID;//here we might want to generate another ID
    m_health=other.m_health;
    m_damage=other.m_damage;
    m_level_multiplier=other.m_level_multiplier;
    m_location=std::make_pair(other.m_location.first, other.m_location.second);
    m_type=other.m_type;

    random_vector = std::move(other.random_vector);
    random_unique_ptr = std::move(other.random_unique_ptr);

    //first we clean the old pointers to avoid memory leaks
    for(int i=0; i< random_values_size; ++i)
        delete[] random_values[i];//delete each array
    delete[] random_values;//delete the main pointer array

    random_values_size=other.random_values_size;//get the other size
    random_values=new int*[random_values_size];//create the array of pointers
    
    random_values = other.random_values;//we basically just have to point to the same memory
    other.random_values = nullptr; //then assign nullptr, not destroy the memory address
    other.random_values_size = 0;
    return *this;
}

bool Animal::atack(const std::shared_ptr<IAtackable>& other){
    other->takeDamage(m_damage*m_level_multiplier);//TODO tweek scaling, it should scale but not just multiply with the level
    return true;
}

bool Animal::move(std::pair<int,int> new_location){
    m_location=std::make_pair(new_location.first, new_location.second);
    return true;
}

bool Animal::takeDamage(const int16_t& damage){
    m_health=(m_health-damage>0) ? m_health-damage : 0;
    return (m_health>0);
}

uint16_t Animal::getID()const{
    return m_ID;
}

std::string Animal::toString(){
    return ("Animal -> ID: "+ std::to_string(m_ID)+
            "Type: "+animalTypeToString(m_type)+
            "Level: " +std::to_string(m_level_multiplier)+
            "Health: "+std::to_string(m_health)+
            "Damage: "+std::to_string(m_damage));
}


static std::string animalTypeToString(AnimalType type){
    switch(type)
    {
        case AnimalType::Wolf:
            return "Wolf";
            break;
        case AnimalType::Rabit:
            return "Rabit";
            break;
        case AnimalType::Doe:
            return "Doe";
            break;
        case AnimalType::Stag:
            return "Stag";
            break;
        default:
            return "Unknown";
    }
}