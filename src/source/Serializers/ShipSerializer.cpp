#include "../../headers/Serializers/ShipSerializer.h"


ShipSerializer::ShipSerializer(const Ship& ship) : ship(ship)
{}

void ShipSerializer::load()
{
    this->__json = json{
        {"id", ship.GetId()},
        {"len", ship.GetLen()},
        {"orientation", ship.GetOrientation()},
        {"segments", ship.GetSegments()}
    };
}
