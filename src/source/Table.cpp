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

Table::Coords::Coords(int x, int y)
{
    this->x = x;
    this->y = y;
}

Table::Coords::Coords() : Coords(0, 0){}

const int& Table::Coords::GetX() const
{
    return this->x;
}

const int& Table::Coords::GetY() const
{
    return this->y;
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
        manager = other.manager;
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
        manager = other.manager;
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
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
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
    std::cout << "______________________________________________________" << "\n";
}


bool Table::add_ship_map(Ship& ship, Coords coord)
{
    std::vector<Coords> coords;
    bool flag = true;
    if (ship.GetOrientation() == HORIZONTAL)
    {
        for (int i = 0; i < ship.GetLen(); i++)
        {
            if (check_point({coord.GetX() + i, coord.GetY()}))
            {
                coords.push_back({coord.GetX() + i, coord.GetY()});
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < ship.GetLen(); i++)
        {   

            if (check_point({coord.GetX(), coord.GetY() + i}))
            {
                coords.push_back({coord.GetX(), coord.GetY() + i});
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        coords_ships[&ship] = coords;
        this->add_ship_table(ship);
    }
    return flag;
    
}


bool Table::check_point(Coords coord)
{   
    if (coord.GetX() < 1 or coord.GetY() < 1 or coord.GetX() > this->width or coord.GetY() > this->height)
    {
        return false;
    }
    int count = 0;
    for (int y = coord.GetY() - 1; y <= coord.GetY() + 1; y++)
    {
        for (int x = coord.GetX() - 1; x <= coord.GetX() + 1; x++)
        {
            if (x < 1 or y < 1 or x > this->width or y > this->height)
            {
                count++;
            }
            else if (cells_[y - 1][x - 1] != SHIP)
            {
                count ++;
            }
        }
    }

    return count == 9;
}


void Table::add_ship_table(Ship& ship)
{

    for (Coords j: this->coords_ships[&ship])
    {
        this->cells_[j.GetY() - 1][j.GetX() - 1] = SHIP;
    }
}



void Table::put_ships()
{
    
    int i = 0;
    for (; i < manager.GetCountShips();)
    {
        int x = 0;
        int y = 0;
        int _or = -1;
        Orientation orie;
        while (x <= 0 || y <= 0 || _or < 0 || _or > 1)
        {
            
            std::cout << "Enter the location of the Ship HORIZONTAL : 0 VERTICAL : 1" << "\n";
            std::cin >> _or;

            if (_or < 0 || _or > 1)
            {
                std::cout << "Bad location try again" << "\n";
                continue;
            }
            orie = (_or == 1) ? VERTICAL : HORIZONTAL;

            std::cout << "Enter the coordinates of the ship's starting points separated by a space and its length: " << manager[i].GetLen() << "\n";
            std::cin >> x >> y;
            
            if (!check_point({x, y}))
            {
                std::cout << "Try again" << "\n";
                continue;
            }
            std::cout << "______________________________________________________" << "\n";
            manager[i].SetOrientation(orie);
            if (!this->add_ship_map(manager[i], {x, y}))
            {
                std::cout << "Try again" << "\n";
                continue;
            }
            i++;
        }
        this->print();

    }
}



bool Table::add_new_ship(Length len, Orientation orientation, Coords coord)
{
    int flag = true;
    if (orientation == VERTICAL)
    {
        for (int i = 0; i < len; i++)
        {
            if (!check_point({coord.GetX(), coord.GetY() + i}))
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (!check_point({coord.GetX() + i, coord.GetY()}))
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        manager.create_ship(len, orientation);
        this->add_ship_map(manager[manager.GetCountShips() - 1], coord);
    }
    return flag;
}