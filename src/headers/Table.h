#ifndef TABLE_H
#define TABLE_H
#include <map>
#include <iostream>
#include "Coord.h"
#include <set>
#include "Ship.h"
#include "Observer.h"
#include "ShipPlacementException.h"
#include "OutOfBoundsException.h"

enum CellState
{
    UNKNOWN = '?',
    EMPTY = '.',
    SHIP = 'S'
};

class Scanner;
class Attack;

class ManagerShipsTableLoader;

class Table
{

    friend ManagerShipsTableLoader;

private:
    int width;
    int height;

    //std::vector<Observer*> observers;
    Observer* observers;
    std::vector<std::vector<CellState>> _cells;
    std::set<Coord> attack_coords;
    std::map<std::reference_wrapper<Ship>, std::vector<Coord>> coords_ships;

public:
    Table();
    Table(Observer* observer);
    Table(int x, int y, Observer* observer);
    ~Table() {};


    Table(const Table &other);
    Table(Table &&other);

    Table& operator=(const Table &other);
    Table& operator=(Table &&other);
    
    void add_ship(Ship& ship, const Coord& coord);
    void add_ship(Ship& ship, int x, int y);

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
    

    void AddObserver(Observer* observer);

    void circle_ship(std::vector<Coord> coords);

    const std::map<std::reference_wrapper<Ship>, std::vector<Coord>>& get_ship_coords() const;


private:
    void add_ship_table(Ship& ship);


};


#endif