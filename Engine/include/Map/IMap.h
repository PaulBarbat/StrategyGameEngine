#pragma once
#include <memory>
#include <vector>
#include <optional>

enum class Terain : uint8_t{
    Grass,
    Stone,
    Dirt
};

struct Tile{
    std::optional<uint16_t> ocupant;// 4 bytes
    bool passable =true; //1 byte
    Terain terainType; //1 bytes
};

class IMap{
protected:
    std::vector<std::shared_ptr<Tile>> m_tiles;
    uint16_t m_ID;
    uint16_t m_size;
public: 
    virtual ~IMap() = default;
    virtual bool isTilePassable(const std::pair<int,int>& location) const =0;
    virtual std::shared_ptr<Tile> getTile(const std::pair<int,int>& location) const = 0;
};