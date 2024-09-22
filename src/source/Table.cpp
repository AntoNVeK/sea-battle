#include "../headers/Table.h"

Table::Table(ManagerShips& manager) : Table(10, 10, manager) {}


Table::Table(int x, int y, ManagerShips& manager) : width(x), height(y), manager(manager) 
{
    if (x <= 0 || y <= 0)
    {
        throw std::invalid_argument("invalid size component");
    }

    cells_.resize(height, std::vector<CellState>(width, EMPTY));

}


Table::Table(const Table &other)
    : width(other.width), height(other.height), manager(other.manager),
      cells_(other.cells_), coords_ships(other.coords_ships)
{
}


Table::Table(Table &&other)
    : width(other.width), height(other.height), manager(other.manager),
      cells_(std::move(other.cells_)), coords_ships(std::move(other.coords_ships))
{
}


Table& Table::operator=(const Table &other)
{
    if (this != &other)
    {
        width = other.width;
        height = other.height;
        cells_ = other.cells_;
        coords_ships = other.coords_ships;

    }
    return *this;
}


Table& Table::operator=(Table &&other) 
{
    if (this != &other)
    {
        width = other.width;
        height = other.height;
        cells_ = std::move(other.cells_);
        coords_ships = std::move(other.coords_ships);

    }
    return *this;
}


const int& Table::GetX() const
{
    return this->width;
}

const int& Table::GetY() const
{
    return this->height;
}

const ManagerShips& Table::GetManager() const
{
    return this->manager;
}


void Table::print() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            switch (cells_[i][j]) {
                case UNKNOWN:
                    std::cout << "?";
                    break;
                case EMPTY:
                    std::cout << ".";
                    break;
                case SHIP:
                    std::cout << "S";
                    break;
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
}
