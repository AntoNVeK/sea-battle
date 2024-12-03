#include "../headers/Table.h"


Table::Table() : Table(10, 10) {}





Table::Table(int x, int y) : width(x), height(y)
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
        observer = other.observer;
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



void Table::add_ship(Ship& ship, const Coord& coord)
{
    std::vector<Coord> coords;

    

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
                throw ShipPlacementException("incorrect ship placement");
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
                throw ShipPlacementException("incorrect ship placement");
            }
        }
    }

    coords_ships[ship] = coords;
    this->add_ship_table(ship);


    
}

void Table::add_ship(Ship& ship, int x, int y)
{
    this->add_ship(ship, Coord(x, y));
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

    for (Coord coord: this->coords_ships[ship])
    {
        this->_cells[coord.GetY() - 1][coord.GetX() - 1] = SHIP;
    }
}



bool Table::shoot(const Coord& coord)
{
    if (coord.GetX() < 1 || coord.GetY() < 1 || coord.GetX() > this->width || coord.GetY() > this->height)
    {
        throw OutOfBoundsException("attack out of bounds");
    }


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
                        if (observer != nullptr)
                            observer->accept();
                        
                        circle_ship(pair.second);
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

void Table::circle_ship(std::vector<Coord> coords)
{
    for (const auto& coord : coords) {

        for (int y = coord.GetY() - 1; y <= coord.GetY() + 1; y++)
        {
            for (int x = coord.GetX() - 1; x <= coord.GetX() + 1; x++)
            {
                if (x >= 1 && y >= 1 && x <= this->width && y <= this->height)
                {
                    attack_coords.insert({x, y});
                }

            }
        }
    }
}



const std::set<Coord>& Table::GetAttackCoords() const
{
    return attack_coords;
}



void Table::AddObserver(Observer* observer)
{
    this->observer = observer;
}

const std::map<std::reference_wrapper<Ship>, std::vector<Coord>>& Table::get_ship_coords() const
{
    return coords_ships;
}

void Table::print_map() const
{
    for (const auto& pair : coords_ships) {
        const Ship& ship = pair.first.get(); // Получаем ссылку на объект Ship
        const std::vector<Coord>& coords = pair.second;

        // Вывод информации о корабле
        std::cout << "Ship ID: " << ship.GetId() << ", Length: " << ship.GetLen() << ", Orientation: " << ship.GetOrientation() << "\n";

        // Вывод координат
        std::cout << "Coordinates: ";
        for (const Coord& coord : coords) {
            std::cout << "(" << coord.GetX() << ", " << coord.GetY() << ") ";
        }
        std::cout << "\n";
    }
}