#ifndef TABLE_H
#define TABLE_H
#include "ManagerShips.h"
#include <map>

#include <iostream>




enum CellState
{
    UNKNOWN,
    EMPTY,
    SHIP
};

class Table
{
public:
    class Coords
    {
        public:
            Coords(int x, int y);
            Coords();
            
            const int& GetX() const;
            const int& GetY() const;
        private:
            int x;
            int y;
    };



private:
    int width;
    int height;
    ManagerShips& manager;
    std::vector<std::vector<CellState>> cells_;
    std::map<Ship*, std::vector<Coords>> coords_ships;

public:
    Table(ManagerShips& manager);
    Table(int x, int y, ManagerShips& manager);
    ~Table() {};


    Table(const Table &other);
    Table(Table &&other);

    Table& operator=(const Table &other);
    Table& operator=(Table &&other);

    

    const int& GetX() const;
    const int& GetY() const;

    const ManagerShips& GetManager() const;
    bool add_ship_map(Ship& ship, Coords coord);
    void add_ship_table(Ship& ship);

    bool add_new_ship(Length len, Orientation orientation, Coords coord);

    bool shoot(Coords coord);
    bool check_point(Coords coord);


    const States GetStateSegmentShip(Coords coord) const;

    void print() const;

    void PrintCoordsShips();
    

};


#endif