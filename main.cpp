#include <MapFactory.h>
#include <StartingMap.h>
#include <iostream>

int main()
{
    std::shared_ptr<IMap> baseMap = MapFactory::createMap("First Map");  
    std::shared_ptr<StartingMap> map = std::dynamic_pointer_cast<StartingMap>(baseMap);
    map->printMap();
    std::cin.get();
    return 0;
}