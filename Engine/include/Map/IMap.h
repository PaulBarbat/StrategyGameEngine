#pragma once
#include <memory>
#include <vector>
#include <optional>

enum class Terain{
    Grass,
    Stone,
    Dirt
};

struct Tile{
    bool passable =true;
    std::optional<uint16_t> Entity;//if something is on the tile
    Terain terainType;
};

class IMap{
protected:
    std::vector<std::shared_ptr<Tile>> tiles;
    uint16_t ID;
    uint16_t size;
public: 
    virtual ~IMap() = default;
    virtual bool isTilePassable(const std::pair<int,int>& location) const =0;
    virtual std::shared_ptr<Tile> getTile(const std::pair<int,int>& location) const = 0;
};