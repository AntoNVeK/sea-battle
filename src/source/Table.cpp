#include "../headers/Table.h"

Table::Table(ManagerShips& manager) : Table(10, 10, manager) {}


Table::Table(int x, int y, ManagerShips& manager) : width(x), height(y), manager(manager) 
{
    if (x <= 0 || y <= 0)
    {
        throw std::invalid_argument("invalid size component");
    }

    cells_.resize(height, std::vector<CellState>(width, EMPTY));
    this->put_ships();
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
            if (check_point({coord.x + i, coord.y}))
            {
                coords.push_back({coord.x + i, coord.y});
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

            if (check_point({coord.x, coord.y + i}))
            {
                coords.push_back({coord.x, coord.y + i});
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
    if (coord.x < 0 or coord.y < 0 or coord.x > this->width or coord.y > this->height)
    {
        return false;
    }
    int count = 0;
    for (int y = coord.y - 1; y <= coord.y + 1; y++)
    {
        for (int x = coord.x - 1; x <= coord.x + 1; x++)
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
        this->cells_[j.y - 1][j.x - 1] = SHIP;
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
        while (x <= 0 or y <= 0 or _or < 0 or _or > 1)
        {
            
            std::cout << "Enter the location of the Ship HORIZONTAL : 0 VERTICAL : 1" << "\n";
            std::cin >> _or;

            if (_or < 0 or _or > 1)
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
