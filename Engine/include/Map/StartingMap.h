#pragma once
#include "IMap.h"

class StartingMap : public IMap{
private:
public:
    StartingMap(const std::vector<std::shared_ptr<Tile>>& tiles);
    StartingMap(std::vector<std::shared_ptr<Tile>>&& tiles);
    bool ocupyTile(uint16_t ID, const std::pair<int,int>& location);
    std::shared_ptr<Tile> getTile(const std::pair<int,int>& location) const;
    bool isTilePassable(const std::pair<int,int>& location) const; 
    void printMap() const;
};