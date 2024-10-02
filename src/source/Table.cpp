#include "../headers/Table.h"

Table::Table(ManagerSkillsObserver& observer) : Table(10, 10, observer) {}


Table::Table(int x, int y, ManagerSkillsObserver& observer) : width(x), height(y), observer(observer)
{
    if (x <= 0 || y <= 0)
    {
        throw std::invalid_argument("invalid size component");
    }

    _cells.resize(height, std::vector<CellState>(width, EMPTY));
    
}


Table::Table(const Table &other)
    : width(other.width), height(other.height),
      _cells(other._cells), attack_coords(other.attack_coords), coords_ships(other.coords_ships), observer(other.observer)
{
}


Table::Table(Table &&other)
    : width(other.width), height(other.height),
      _cells(std::move(other._cells)), attack_coords(std::move(other.attack_coords)), coords_ships(std::move(other.coords_ships)), observer(other.observer)
{
}


Table& Table::operator=(const Table &other)
{
    if (this != &other)
    {
        width = other.width;
        height = other.height;
        observer = other.observer;
        _cells = other._cells;
        attack_coords = other.attack_coords;
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
        _cells = std::move(other._cells);
        attack_coords = std::move(other.attack_coords);
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



const States Table::GetStateSegmentShip(const Coord& coord) const
{
    int i = -1;
    States state = FULL;

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

const States Table::GetStateSegmentShip(int x, int y) const
{
    return this->GetStateSegmentShip(Coord(x, y));
}

// Not use, will delete
void Table::print(bool is_enemy) const {

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            switch (_cells[i][j]) {
                case UNKNOWN:
                    std::cout << "?";
                    break;
                case EMPTY:
                    std::cout << ".";
                    break;
                case SHIP:{
                    States state = GetStateSegmentShip(j, i);
                    if (state == FULL)
                        std::cout << "S";
                    else if (state == HALF_DESTROYED)
                        std::cout << "*";
                    else if (state == DESTROYED)
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


bool Table::add_ship(Ship& ship, const Coord& coord)
{
    std::vector<Coord> coords;
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

bool Table::add_ship(Ship& ship, int x, int y)
{
    return this->add_ship(ship, Coord(x, y));
}

bool Table::check_point(const Coord& coord)
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

bool Table::check_point(int x, int y)
{
    return this->check_point(Coord(x, y));
}

void Table::add_ship_table(Ship& ship)
{

    for (Coord j: this->coords_ships[ship])
    {
        this->_cells[j.GetY() - 1][j.GetX() - 1] = SHIP;
    }
}




bool Table::shoot(const Coord& coord)
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
                    if (pair.first.get().is_destroyed())
                    {
                        observer.accept();
                        circle_ship(pair.first.get());
                    }
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
    attack_coords.insert(coord);
    return flag;
}

bool Table::shoot(int x, int y)
{
    return this->shoot(Coord(x, y));
}


const std::vector<std::vector<CellState>>& Table::GetCoords() const
{
    return _cells;
}

void Table::circle_ship(Ship& ship)
{
    // TODO
}