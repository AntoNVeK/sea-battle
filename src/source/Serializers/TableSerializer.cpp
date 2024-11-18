#include "../../headers/Serializers/TableSerializer.h"


TableSerializer::TableSerializer(const Table& table) : table(table)
{}

void TableSerializer::load()
{
    __json = json::object();
    __json.emplace("width", table.GetX());
    __json.emplace("height", table.GetY());
    __json.emplace("cells", table.GetCoords());
    json j = json::array();
    for (const auto& coord : table.GetAttackCoords()) {
        CoordSerializer s(coord);
        s.load();
        j.push_back(s.get());
    }
    __json.emplace("AttackCoords", j);
    
    j = json::array();
    auto coords_ships = table.get_ship_coords();
    for (const auto& pair: coords_ships)
    {
        json j1 = json::array();
        for (const auto& coord : coords_ships[pair.first])
        {    
            CoordSerializer s(coord);
            s.load();
            j1.push_back(s.get());
        }
        json j2;
        j2[std::to_string(pair.first.get().GetId())] = j1;
        j.push_back(j2);
    }
    __json.emplace("ships_coords", j);
    
}