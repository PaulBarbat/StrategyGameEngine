#include "StartingMap.h"
#include "Utils.h"
#include <iostream>
#include <cmath>

StartingMap::StartingMap(const std::vector<std::shared_ptr<Tile>>& tiles){
    std::cout<<"Normal constructor"<<std::endl;
}
StartingMap::StartingMap(std::vector<std::shared_ptr<Tile>>&& tiles){
    std::cout<<"Constructor with rvalue param"<<std::endl;
    this->tiles = std::move(tiles);
    this->size = static_cast<uint16_t>(std::sqrt(tiles.size()));
    this->ID=Utils::getID();
}

std::shared_ptr<Tile> StartingMap::getTile(const int& x, const int& y) const{
    return tiles.at(size*x+y);
}

bool StartingMap::isTilePassable(const int& x, const int& y) const{
    return tiles.at(size*x+y)->passable;
}