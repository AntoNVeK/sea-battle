#include "../headers/Ship.h"



Ship::Ship(int id) : Ship(Length::ONE, id)
{}

Ship::Ship(Length len, int id) : Ship(len, Orientation::HORIZONTAL, id)
{}

Ship::Ship(Length len, Orientation orientation, int id)
{
    this->count_destroyed = 0;
    this->_len = len;
    this->_orientation = orientation;
    this->id = id;
    for (std::uint8_t i = 0; i < this->_len; i++)
    {
        this->_segments.push_back(States::FULL);
    }
}



Ship::Ship(const Ship &other)
{  
    this->_len = other._len;
    this->_orientation = other._orientation;
    this->_segments = other._segments;
    this->id = other.id;
}

Ship::Ship(Ship &&other)
{    
    this->_len = other._len;
    this->_orientation = other._orientation;
    this->_segments = std::move(other._segments);
    this->id = other.id;
}


Ship& Ship::operator=(const Ship &other)
{
    if (this != &other)
    {
        this->_len = other._len;
        this->_orientation = other._orientation;
        this->_segments = other._segments;
        this->id = other.id;
    }
    return *this;
}



Ship& Ship::operator=(Ship &&other)
{
    if (this != &other)
    {
        this->_len = other._len;
        this->_orientation = other._orientation;
        this->_segments = std::move(other._segments);
        this->id = other.id;
    }
    return *this;
}




const Length& Ship::GetLen() const
{
    return this->_len;
}


const Orientation& Ship::GetOrientation() const
{
    return this->_orientation;
}


const std::vector<States>& Ship::GetSegments() const
{
    return this->_segments;
}


void Ship::shoot(std::uint8_t index_segment)
{
    if (index_segment >= this->_len || index_segment < 0)
    {
        throw std::runtime_error("Incorrect index");
    }
    if (this->_segments[index_segment] == States::FULL)
    {
        this->_segments[index_segment] = States::HALF_DESTROYED;
    }
    else if (this->_segments[index_segment] == States::HALF_DESTROYED)
    {
        this->_segments[index_segment] = States::DESTROYED;
        this->count_destroyed ++;
    }
    else if (this->_segments[index_segment] == States::DESTROYED)
    {
        throw std::runtime_error("The segment has already been destroyed");
    }

}

void Ship::SetOrientation(Orientation orientation)
{
    this->_orientation = orientation;
}


bool Ship::is_destroyed() const
{
    for (const auto& segment : _segments)
    {
        if (segment != DESTROYED)
        {
            return false;
        }
    }
    return true;
}

const int Ship::GetId() const
{
    return id;
}

namespace std
{
    
    bool operator<(const std::reference_wrapper<Ship>& a, const std::reference_wrapper<Ship>& b)
    {
        return a.get().GetId() < b.get().GetId();
    }

}