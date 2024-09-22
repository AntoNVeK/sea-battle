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


typedef struct Coords
{
    int x;
    int y;
}Coords;


class Table
{
private:
    int width;
    int height;
    ManagerShips& manager;
    std::vector<std::vector<CellState>> cells_;
    std::map<Ship*, std::vector<Coords>> coords_ships;



    bool add_ship_map(Ship& ship, Coords coord);
    void add_ship_table(Ship& ship);

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


    void add_new_ship(Ship ship, Coords coord);
    void put_ships();

    //void shoot(Coords coord);
    bool check_point(Coords coord);
    
    void print() const;


};


#endif