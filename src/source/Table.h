#ifndef TABLE_H
#define TABLE_H
#include "ManagerShips.h"

enum CellState
{
    UNKNOWN,
    EMPTY,
    SHIP
};



class Table
{
private:
    std::size_t width;
    std::size_t height;
    std::vector<std::vector<CellState>> cells_;
    ManagerShips& manager;



public:
    Table(std::size_t x, std::size_t y);
    Table();
    ~Table();


    Table(const Table &other);
    Table(Table &&other);

    Table& operator=(const Table &other);
    Table& operator=(Table &&other);



    const std::size_t& GetX() const;



};


#endif