#ifndef COORD_SERIALIZER_H
#define COORD_SERIALIZER_H
#include "Serializer.h"
#include "../Coord.h"
#include "ShipSerializer.h"
class CoordSerializer : public Serializer
{

private:
    const Coord& coord;
    
public:
    CoordSerializer(const Coord& coord);

    void load() override;

};

#endif