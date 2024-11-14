#ifndef SHIP_SERIALIZER_H
#define SHIP_SERIALIZER_H
#include "Serializer.h"
#include "Table.h"

class ShipSerializer : public Serializer
{

private:
    Ship& ship;
    
public:
    ShipSerializer(Ship& ship);

    void load() override;

};

#endif