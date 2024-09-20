#include "../headers/ManagerShips.h"

ManagerShips::ManagerShips() : ManagerShips(0, {}) {}
ManagerShips::ManagerShips(std::size_t numShips, const std::initializer_list<Length>& shipLengths)
{
    auto it = shipLengths.begin();
    for (std::size_t i = 0; i < numShips; i++)
    {
        if (it != shipLengths.end())
        {
            this->create_ship(*it);
            ++it;
        }
        else
        {
            throw std::invalid_argument("Number of ships exceeds the number of provided lengths.");
        }
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
    this->ships.push_back(Ship(len, orientation));
}


void ManagerShips::create_ship(Length len)
{
    this->ships.push_back(Ship(len, HORIZONTAL));
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