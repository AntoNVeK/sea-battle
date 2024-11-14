#ifndef SHIP_SERIALIZER_H
#define SHIP_SERIALIZER_H
#include "Serializer.h"
#include "../Ship.h"

class ShipSerializer : public Serializer
{

private:
    const Ship& ship;
    
public:
    ShipSerializer(const Ship& ship);

    void load() override;

};

#endif