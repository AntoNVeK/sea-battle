#include "../headers/Coord.h"





Coord::Coord(int x, int y)
{
    this->x = x;
    this->y = y;
}

Coord::Coord() : Coord(1, 1){}

Coord::Coord(const Coord &other)
    : x(other.x), y(other.y)
{    }

Coord::Coord(Coord &&other)
    : x(other.x), y(other.y)
{    }


Coord& Coord::operator=(const Coord &other)
{
    if (this != &other)
    {
        this->x = other.x;
        this->y = other.y;

    }
    return *this;
}

Coord& Coord::operator=(Coord &&other)
{
    if (this != &other)
    {
        this->x = other.x;
        this->y = other.y;

    }
    return *this;
}


const int& Coord::GetX() const
{
    return this->x;
}

const int& Coord::GetY() const
{
    return this->y;
}




bool Coord::operator<(const Coord& other) const
{
    if (x < other.x) return true;
        if (x > other.x) return false;
        return y < other.y;
}