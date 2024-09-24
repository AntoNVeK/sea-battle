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
    std::vector<std::vector<CellState>> _cells;
    std::vector<std::vector<CellState>> _hidden_cells;
    std::map<std::reference_wrapper<Ship>, std::vector<Coords>> coords_ships;

public:
    Table(ManagerShips& manager);
    Table(int x, int y, ManagerShips& manager);
    ~Table() {};


    Table(const Table &other);
    Table(Table &&other);

    Table& operator=(const Table &other);
    Table& operator=(Table &&other);
    
    bool add_ship(Ship& ship, Coords coord);
    bool add_new_ship(Length len, Orientation orientation, Coords coord);
    bool shoot(Coords coord);
    bool check_point(Coords coord);
    
    
    void print(const std::vector<std::vector<CellState>>& table) const;
    void print_coords_ships();
    
    const States& GetStateSegmentShip(std::vector<std::vector<CellState>> table, Coords coord) const;

    const int& GetX() const;
    const int& GetY() const;
    const ManagerShips& GetManager() const;
    const std::vector<std::vector<CellState>>& GetCells() const;
    const std::vector<std::vector<CellState>>& GetHiddenCells() const;

private:
    void add_ship_table(Ship& ship);
};


#endif