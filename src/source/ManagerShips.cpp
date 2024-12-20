#include "../headers/ManagerShips.h"

ManagerShips::ManagerShips() : ManagerShips({}) {}
ManagerShips::ManagerShips(const std::initializer_list<Length>& shipLengths)
{
    for (const auto& length : shipLengths)
    {
        this->create_ship(length);
    }

    
}


ManagerShips::ManagerShips(const std::vector<Length>& shipLengths)
{
    for (const auto& length : shipLengths)
    {
        this->create_ship(length);
    }

    
}
ManagerShips::ManagerShips(const ManagerShips &other)
{
    this->ships = other.ships;
}



ManagerShips::ManagerShips(ManagerShips &&other)
{
    this->ships = std::move(other.ships);
}




ManagerShips& ManagerShips::operator=(const ManagerShips &other)
{
    if (this != &other)
    {
        this->ships = other.ships;
    }
    return *this;
}
ManagerShips& ManagerShips::operator=(ManagerShips &&other)
{
    if (this != &other)
    {
        this->ships = std::move(other.ships);
    }
    return *this;
}



void ManagerShips::create_ship(Length len, Orientation orientation)
{
    this->ships.push_back(Ship(len, orientation, ships.size()));
    
}


void ManagerShips::create_ship(Length len)
{
    this->create_ship(len, HORIZONTAL);
}


const std::vector<Ship>& ManagerShips::GetShips() const
{
    return this->ships;
}



Ship& ManagerShips::operator[](std::uint8_t index)
{
    return this->ships.at(index);
}

const Ship& ManagerShips::operator[](std::uint8_t index) const
{
    return this->ships.at(index);
}
std::size_t ManagerShips::GetCountShips() const
{
    return this->ships.size();
}

bool ManagerShips::all_destroyed_ships()
{
    for (auto& ship : ships)
    {
        if (!ship.is_destroyed())
        {
            return false;
        }
    }
    return true;
}


