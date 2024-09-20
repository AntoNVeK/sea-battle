#include "../headers/Ship.h"



Ship::Ship() : Ship(Length::ONE)
{}

Ship::Ship(Length len) : Ship(len, Orientation::HORIZONTAL)
{}

Ship::Ship(Length len, Orientation orientation)
{
    this->_len = len;
    this->_orientation = orientation;
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
}

Ship::Ship(Ship &&other)
{    
    this->_len = other._len;
    this->_orientation = other._orientation;
    this->_segments = std::move(other._segments);
}


Ship& Ship::operator=(const Ship &other)
{
    if (this != &other)
    {
        this->_len = other._len;
        this->_orientation = other._orientation;
        this->_segments = other._segments;
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
    if (index_segment >= this->_len or index_segment < 0)
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
    }
    else if (this->_segments[index_segment] == States::DESTROYED)
    {
        throw std::runtime_error("The segment has already been destroyed");
    }

}
