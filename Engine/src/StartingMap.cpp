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
    this->size = static_cast<uint16_t>(std::sqrt(this->tiles.size()));
    this->ID=Utils::getID();
}

bool StartingMap::ocupyTile(uint16_t ID, const std::pair<int,int>& location){
    if(this->isTilePassable(location)){
        tiles.at(size*location.first+location.second)->passable=false;
        return true;
    }
    return false;
}

std::shared_ptr<Tile> StartingMap::getTile(const std::pair<int,int>& location) const{
    return tiles.at(size*location.first+location.second);
}

bool StartingMap::isTilePassable(const std::pair<int,int>& location) const{
    return tiles.at(size*location.first+location.second)->passable;
}

void StartingMap::printMap() const{
    std::cout<<"Here is the map:"<<std::endl;
    std::cout<<"ID: "<<this->ID<<std::endl;
    std::cout<<"Map size: "<<this->tiles.size()<<" "<<this->size<<std::endl;
    for(int i=0; i<this->size; ++i){
        for(int j=0; j<this->size; ++j){
            std::cout<<static_cast<int>(this->tiles.at(i*size+j).get()->terainType)<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}