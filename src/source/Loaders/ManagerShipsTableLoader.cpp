#include "../../headers/Loaders/ManagerShipsTableLoader.h"


ManagerShipsTableLoader::ManagerShipsTableLoader(ManagerShips& manager, Table& table) : manager(manager), table(table)
{}

void ManagerShipsTableLoader::loadFromJson(const json& j)
{
    table.height = j["Table"]["height"];
    table.height = j["Table"]["width"];

    table.attack_coords = {};

    for (const auto& coordJson : j["Table"]["AttackCoords"]) {
        Coord coord(coordJson[0], coordJson[1]);
        table.attack_coords.insert(coord);
    }

    manager.ships = {};

    for (const auto& shipJson : j["ManagerShips"]) {
        int id = shipJson["id"];
        int len = shipJson["len"];
        int orientation = shipJson["orientation"];

        manager.create_ship((Length)len, (Orientation)orientation);
        
        manager[id]._segments = {};

        for (const auto& segmentJson : shipJson["segments"]) {
            int segmentValue = segmentJson;
            States state;
            switch (segmentValue) {
                case 'S':
                    state = FULL;
                    break;
                case '*':
                    state = HALF_DESTROYED;
                    break;
                case '#':
                    state = DESTROYED;
                    break;
            }
            manager[id]._segments.push_back(state);
        }
        
    }
    table._cells = {};
    table._cells.resize(table.height, std::vector<CellState>(table.width, EMPTY));
    

    table.coords_ships = {};
    for (int i = 0; i < manager.GetCountShips(); i++)
    {
        table.add_ship(manager[i], getFirstCoordForId(j["Table"]["ships_coords"], i));
    }


}



Coord ManagerShipsTableLoader::getFirstCoordForId(const json& j, int id) {
    for (const auto& shipCoordsJson : j) {
        for (const auto& shipId : shipCoordsJson.items()) {
            int shipIdValue = std::stoi(shipId.key());
            if (shipIdValue == id) {
                const json& coordsJson = shipId.value();
                if (!coordsJson.empty()) {
                    const json& firstCoordJson = coordsJson[0];
                    return Coord(firstCoordJson[0], firstCoordJson[1]);
                }
            }
        }
    }
    throw std::runtime_error("No coordinates found for the given id");
}