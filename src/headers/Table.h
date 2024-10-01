#ifndef TABLE_H
#define TABLE_H
#include "ManagerShips.h"
#include <map>
#include <iostream>
#include <Coord.h>
#include <set>


enum CellState
{
    UNKNOWN,
    EMPTY,
    SHIP
};



class Table
{

private:
    int width;
    int height;

    std::vector<std::vector<CellState>> _cells;
    std::vector<std::vector<CellState>> _hidden_cells;

    std::map<std::reference_wrapper<Ship>, std::vector<Coord>> coords_ships;

public:
    Table();
    Table(int x, int y);
    ~Table() {};


    Table(const Table &other);
    Table(Table &&other);

    Table& operator=(const Table &other);
    Table& operator=(Table &&other);
    
    bool add_ship(Ship& ship, const Coord& coord);
    bool add_ship(Ship& ship, int x, int y);

    bool shoot(const Coord& coord);
    bool shoot(int x, int y);
    
    bool check_point(const Coord& coord);
    bool check_point(int x, int y);

    void print(bool is_enemy) const;


    const States GetStateSegmentShip(const Coord& coord) const;
    const States GetStateSegmentShip(int x, int y) const;


    const int& GetX() const;
    const int& GetY() const;
    const std::vector<std::vector<CellState>>& GetCoords() const;

private:
    void add_ship_table(Ship& ship);
};


#endif