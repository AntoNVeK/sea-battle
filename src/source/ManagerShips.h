#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include "Ship.h"

class ManagerShips
{
private:
    std::vector<Ship> ships;

public:
    ManagerShips();
    ManagerShips(std::size_t numShips, const std::initializer_list<Length>& shipLenths);
    ~ManagerShips() {};

    ManagerShips(const ManagerShips &other);
    ManagerShips(ManagerShips &&other);


    ManagerShips& operator=(const ManagerShips &other);
    ManagerShips& operator=(ManagerShips &&other);

    void create_ship(Length len, Orientation orientation);
    void create_ship(Length len);



    Ship& operator[](std::uint8_t index);
    const Ship& operator[](std::uint8_t index) const;

    const std::vector<Ship>& GetShips() const;
    std::size_t GetCountShips() const;

};


#endif