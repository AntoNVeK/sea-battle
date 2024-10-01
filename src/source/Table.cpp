#include "../headers/Table.h"

Table::Table(ManagerShips& manager) : Table(10, 10, manager) {}


Table::Table(int x, int y, ManagerShips& manager) : width(x), height(y), manager(manager) 
{
    if (x <= 0 || y <= 0)
    {
        throw std::invalid_argument("invalid size component");
    }

    _cells.resize(height, std::vector<CellState>(width, EMPTY));
    _hidden_cells.resize(height, std::vector<CellState>(width, UNKNOWN));

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
      _cells(other._cells), _hidden_cells(other._hidden_cells),coords_ships(other.coords_ships)
{
}


Table::Table(Table &&other)
    : width(other.width), height(other.height), manager(other.manager),
      _cells(std::move(other._cells)), _hidden_cells(std::move(other._hidden_cells)), coords_ships(std::move(other.coords_ships))
{
}


Table& Table::operator=(const Table &other)
{
    if (this != &other)
    {
        width = other.width;
        height = other.height;
        manager = other.manager;
        _cells = other._cells;
        _hidden_cells = other._hidden_cells;
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
        _cells = std::move(other._cells);
        _hidden_cells = std::move(other._hidden_cells);
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

const States& Table::GetStateSegmentShip(Coords coord) const
{
    int i = -1;
    States a = FULL;
    States& state = a;
    bool flag = false;
    for (const auto& pair: coords_ships)
    {
        i = 0;
        for (const auto& cor : pair.second)
        {
            if (cor.GetX() == coord.GetX() + 1 && cor.GetY() == coord.GetY() + 1)
            {
                flag = true;
                state = pair.first.get().GetSegments()[i];
                break;
            }
            i++;
        }
        if (flag)
        {
            break;
        }
    }

    return state;
    
}



void Table::print(const std::vector<std::vector<CellState>>& table) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            switch (table[i][j]) {
                case UNKNOWN:
                    std::cout << "?";
                    break;
                case EMPTY:
                    std::cout << ".";
                    break;
                case SHIP:{
                    if (GetStateSegmentShip({j,i}) == FULL)
                        std::cout << "S";
                    else if (GetStateSegmentShip({j,i}) == HALF_DESTROYED)
                        std::cout << "*";
                    else if (GetStateSegmentShip({j,i}) == DESTROYED)
                        std::cout << "#";
                    break;
                    }
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "______________________________________________________" << "\n";
}


bool Table::add_ship(Ship& ship, Coords coord)
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
        coords_ships[ship] = coords;
        this->add_ship_table(ship);
    }
    return flag;
    
}


bool Table::check_point(Coords coord)
{   
    if (coord.GetX() < 1 || coord.GetY() < 1 || coord.GetX() > this->width || coord.GetY() > this->height)
    {
        return false;
    }
    int count = 0;
    for (int y = coord.GetY() - 1; y <= coord.GetY() + 1; y++)
    {
        for (int x = coord.GetX() - 1; x <= coord.GetX() + 1; x++)
        {
            if (x < 1 || y < 1 || x > this->width || y > this->height)
            {
                count++;
            }
            else if (_cells[y - 1][x - 1] != SHIP)
            {
                count ++;
            }
        }
    }

    return count == 9;
}


void Table::add_ship_table(Ship& ship)
{

    for (Coords j: this->coords_ships[ship])
    {
        this->_cells[j.GetY() - 1][j.GetX() - 1] = SHIP;
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
        this->add_ship(manager[manager.GetCountShips() - 1], coord);
    }
    return flag;
}


bool Table::shoot(Coords coord)
{
    bool flag = false;
    int i = -1;

    if (_cells[coord.GetY() - 1][coord.GetX() - 1] == SHIP)
    {
        for (const auto& pair: coords_ships)
        {
            i = 0;
            for (const auto& cor : coords_ships[pair.first])
            {
                if (cor.GetX() == coord.GetX() && cor.GetY() == coord.GetY())
                {
                    pair.first.get().shoot(i);
                    _hidden_cells[coord.GetY() - 1][coord.GetX() - 1] = SHIP;
                    flag = true;
                    break;
                }
                i++;
            }
            if (flag)
            {
                break;
            }
        }
    }
    else
    {
        _hidden_cells[coord.GetY() - 1][coord.GetX() - 1] = EMPTY;
    }
    return flag;
}







void Table::print_coords_ships() {
    for (const auto& pair : coords_ships) {
        std::cout << "Ship: " << pair.first.get().GetLen() << std::endl;
        std::cout << "Coords: ";
        for (const auto& coord : pair.second) {
            std::cout << "(" << coord.GetX() << ", " << coord.GetY() << ") ";
        }
        std::cout << std::endl;
    }
}


const std::vector<std::vector<CellState>>& Table::GetCells() const
{
    return _cells;
}


const std::vector<std::vector<CellState>>& Table::GetHiddenCells() const
{
    return _hidden_cells;
}