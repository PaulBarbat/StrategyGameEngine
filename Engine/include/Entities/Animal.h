#pragma once

#include "IEntity.h"
#include <vector>

class Animal:public IEntity{
private:
    std::vector<std::shared_ptr<int>> random_vector;
    std::unique_ptr<int> random_unique_ptr;
    int** random_values;
    size_t random_values_size;
public:
    Animal(int16_t health ,uint16_t damage);
    ~Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    Animal(Animal&& other) noexcept;
    Animal& operator=(Animal&& other) noexcept;
    bool atack(const std::shared_ptr<IAtackable>& other);
    bool move();
    bool takeDamage(const int16_t& damage);
    void toString();
};