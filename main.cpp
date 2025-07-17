#include <MapFactory.h>
#include <StartingMap.h>
#include <iostream>
#include <AnimalFactory.h>

int main()
{
    std::shared_ptr<IMap> baseMap = MapFactory::createMap("First Map");  
    std::shared_ptr<StartingMap> map = std::dynamic_pointer_cast<StartingMap>(baseMap);
    map->printMap();

    //geting alocation to put an animal
    std::pair<int,int> location(10,10);
    std::unique_ptr<Animal> wolf;
    //logic that will go inside a function like placeAnimal
    if(map->isTilePassable(location.first, location.second))
    {
        wolf=AnimalFactory::createAnimal(AnimalType::Stag, location);
        if(wolf)
        {
            map->ocupyTile(wolf->getID(), location);
        }
    }
    std::cout<<wolf->toString()<<std::endl;
    std::cin.get();
    return 0;
}