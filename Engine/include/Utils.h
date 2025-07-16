#pragma once
#include <memory>

class Utils{
private:
    inline static uint16_t currentID = 1;
public:
    static uint16_t getID(){
        return currentID++;
    } 
};