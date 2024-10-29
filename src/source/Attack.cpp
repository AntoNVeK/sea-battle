#include "../headers/Attack.h"


Attack::Attack(ManagerShips& manager) : manager(manager)
{}


void Attack::use()
{
    int index_ship = get_random_index_ship_for_attack(manager);
    
    int index_for_attack = get_random_index_segment_ship(manager[index_ship]);

    manager[index_ship].shoot(index_for_attack);

}



int Attack::get_random_index_ship_for_attack(const ManagerShips& manager)
{

    std::vector<int> alive_ships;

    int index = 0;

    for (const auto &ship : manager.GetShips())
    {
        if (!ship.is_destroyed())
            alive_ships.push_back(index);
        
        index++;
    }
    srand(time(NULL));

    return alive_ships[rand() % manager.GetCountShips()];

}


int Attack::get_random_index_segment_ship(const Ship& ship)
{
    std::vector<int> alive_segments;


    for (std::uint8_t i = 0; i < ship.GetLen(); ++i)
    {
        if (ship.GetSegments()[i] != DESTROYED)
            alive_segments.push_back(i);
    }

    srand(time(NULL));

    return alive_segments[rand() % alive_segments.size()];
}
