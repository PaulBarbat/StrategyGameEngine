#include "StartingMap.h"

StartingMap::StartingMap(uint16_t size){
    this->size=size;//add size x size elements in tiles, make a factory for it
}

std::shared_ptr<Tile> StartingMap::getTile(const int& x, const int& y) const{
    return tiles.at(size*x+y);
}

bool StartingMap::isTilePassable(const int& x, const int& y) const{
    return tiles.at(size*x+y)->passable;
}