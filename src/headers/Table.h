#ifndef TABLE_H
#define TABLE_H
#include <map>
#include <iostream>
#include "Coord.h"
#include <set>
#include "Ship.h"
#include "ManagerSkillsObserver.h"

enum CellState
{
    UNKNOWN = '?',
    EMPTY = '.',
    SHIP = 'S'
};

class ManagerSkillsObserver;


class Table
{

private:
    int width;
    int height;

    ManagerSkillsObserver& observer;
    std::vector<std::vector<CellState>> _cells;
    std::set<Coord> attack_coords;
    std::map<std::reference_wrapper<Ship>, std::vector<Coord>> coords_ships;

public:
    Table(ManagerSkillsObserver& observer);
    Table(int x, int y, ManagerSkillsObserver& observer);
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

    const States GetStateSegmentShip(const Coord& coord) const;
    const States GetStateSegmentShip(int x, int y) const;


    const int& GetX() const;
    const int& GetY() const;

    const std::vector<std::vector<CellState>>& GetCoords() const;
    const std::set<Coord>& GetAttackCoords() const;
    
private:
    void add_ship_table(Ship& ship);
    void circle_ship(std::vector<Coord> coords);
};


#endif