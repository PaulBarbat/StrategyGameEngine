#pragma once
#include "IMap.h"

class StartingMap : public IMap{
private:
public:
    StartingMap(uint16_t size);
    std::shared_ptr<Tile> getTile(const int& x, const int& y) const;
    bool isTilePassable(const int& x, const int& y) const; 
};