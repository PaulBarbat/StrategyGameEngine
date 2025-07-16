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

void StartingMap::printMap() const{
    std::cout<<"Here is the map:"<<std::endl;
    std::cout<<"ID: "<<this->ID<<std::endl;
    std::cout<<"Map size: "<<this->tiles.size()<<std::endl;
    for(int i=0; i<this->size; ++i){
        for(int j=0; j<this->size; ++j){
            std::cout<<this->tiles.at(i*size+j)<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}