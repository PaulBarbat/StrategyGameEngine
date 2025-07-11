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
private:
    uint16_t ID;
    std::vector<std::shared_ptr<Tile>> tiles;
public: 
    virtual ~IMap() = default;
    virtual std::shared_ptr<Tile> getTile(const int& x, const int& y) const = 0;
};