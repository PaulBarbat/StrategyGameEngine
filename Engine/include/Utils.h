#pragma once
#include <memory>

class Utils{
private:
    static uint16_t currentID;
public:
    static uint16_t getID(){
        return currentID++;
    } 
};