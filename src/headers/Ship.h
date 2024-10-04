#ifndef SHIP_H
#define SHIP_H

#include <cstdint>
#include <vector>
#include <stdexcept>
#include <functional>
enum Orientation
{
    HORIZONTAL,
    VERTICAL
};

enum States
{
    FULL = 'S',
    HALF_DESTROYED = '*',
    DESTROYED = '#'
};

enum Length
{
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4
};


class Ship
{
private:
    Orientation _orientation;
    std::vector<States> _segments;
    Length _len;
    std::size_t count_destroyed;
public:
    Ship();
    Ship(Length len, Orientation orientation);
    Ship(Length len);


    Ship(const Ship &other);
    Ship(Ship &&other);

    ~Ship() {};

    Ship& operator=(const Ship &other);
    Ship& operator=(Ship &&other);

    void shoot(std::uint8_t index_segment);


    void SetOrientation(Orientation orientation);


    const Length& GetLen() const;
    const Orientation& GetOrientation() const;
    const std::vector<States>& GetSegments() const;

    bool is_destroyed() const;

};


namespace std
{
    
bool operator<(const std::reference_wrapper<Ship>& a, const std::reference_wrapper<Ship>& b);

}

#endif