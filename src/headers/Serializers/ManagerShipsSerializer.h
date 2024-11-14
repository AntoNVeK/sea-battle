#ifndef SKILLRESULT_SERIALIZER_H
#define SKILLRESULT_SERIALIZER_H
#include "Serializer.h"
#include "../ManagerShips.h"
#include "ShipSerializer.h"
class ManagerShipsSerializer : public Serializer
{

private:
    ManagerShips& manager;
    
public:
    ManagerShipsSerializer(ManagerShips& manager);

    void load() override;

};

#endif