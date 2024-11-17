#ifndef SKILLRESULT_SERIALIZER_H
#define SKILLRESULT_SERIALIZER_H
#include "Serializer.h"
#include "../ManagerShips.h"
#include "ShipSerializer.h"
class ManagerShipsSerializer : public Serializer
{

private:
    const ManagerShips& manager;
    
public:
    ManagerShipsSerializer(const ManagerShips& manager);

    void load() override;

};

#endif