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



class Table
{

    friend Scanner;
    friend Attack;


private:
    int width;
    int height;

    Observer* observer;
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

    void shoot(const Coord& coord);
    void shoot(int x, int y);
    
    bool check_point(const Coord& coord);
    bool check_point(int x, int y);

    const States GetStateSegmentShip(const Coord& coord) const;
    const States GetStateSegmentShip(int x, int y) const;


    const int& GetX() const;
    const int& GetY() const;

    const std::vector<std::vector<CellState>>& GetCoords() const;
    const std::set<Coord>& GetAttackCoords() const;
    

    void SetObserver(Observer* observer);


private:
    void add_ship_table(Ship& ship);
    void circle_ship(std::vector<Coord> coords);

};


#endif