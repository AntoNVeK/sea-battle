#include "../../headers/Serializers/CoordSerializer.h"


CoordSerializer::CoordSerializer(const Coord& coord) : coord(coord)
{}

void CoordSerializer::load()
{
    __json = json::array();
    __json.push_back(coord.GetX());
    __json.push_back(coord.GetY());
}
