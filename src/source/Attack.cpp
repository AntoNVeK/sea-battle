#include "../headers/Attack.h"


Attack::Attack()
{}


void Attack::use(Table& table)
{
    Ship& ship = get_random_ship_for_attack(table);

    ship.shoot(get_random_index_segment_ship(ship));

    if (ship.is_destroyed())
    {
        table.circle_ship(table.coords_ships[ship]);
        table.observer->accept();
    }

}



Ship& Attack::get_random_ship_for_attack(const Table& table)
{

    std::vector<std::reference_wrapper<Ship>> alive_ships;


    for (const auto &ship_coords : table.coords_ships)
    {
        if (!ship_coords.first.get().is_destroyed())
            alive_ships.push_back(ship_coords.first);
    }
    srand(time(NULL));

    return alive_ships[rand() % alive_ships.size()].get();

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
