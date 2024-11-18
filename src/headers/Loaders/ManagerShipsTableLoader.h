#ifndef MANAGER_SHIPS_TABLE_LOADER_H
#define MANAGER_SHIPS_TABLE_LOADER_H
#include "Loader.h"
#include "../ManagerShips.h"
#include "../Table.h"

class ManagerShipsTableLoader : public Loader
{

private:
    ManagerShips& manager;
    Table& table;

public:
    ManagerShipsTableLoader(ManagerShips& manager, Table& table);

    void loadFromJson(const json& j) override;

private:
    Coord getFirstCoordForId(const json& j, int id);
};

#endif