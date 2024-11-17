#include "../../headers/Serializers/ManagerShipsSerializer.h"


ManagerShipsSerializer::ManagerShipsSerializer(const ManagerShips& manager) : manager(manager)
{}

void ManagerShipsSerializer::load()
{
    __json = json::array();
    for (const auto& ship : manager.GetShips()) {
        ShipSerializer s(ship);
        s.load();
        __json.push_back(s.get());
    }
}
