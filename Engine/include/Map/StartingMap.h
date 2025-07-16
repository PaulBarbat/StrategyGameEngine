#pragma once
#include "IMap.h"

class StartingMap : public IMap{
private:
public:
    StartingMap(const std::vector<std::shared_ptr<Tile>>& tiles);
    StartingMap(std::vector<std::shared_ptr<Tile>>&& tiles);
    std::shared_ptr<Tile> getTile(const int& x, const int& y) const;
    bool isTilePassable(const int& x, const int& y) const; 
    void printMap() const;
};