#pragma once
#include "IMap.h"

class StartingMap : public IMap{
private:
public:
    std::shared_ptr<Tile> getTile(const int& x, const int& y) const; 
};