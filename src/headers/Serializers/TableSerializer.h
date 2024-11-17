#ifndef TABLE_SERIALIZER_H
#define TABLE_SERIALIZER_H
#include "Serializer.h"
#include "../Table.h"
#include "CoordSerializer.h"
class TableSerializer : public Serializer
{

private:
    const Table& table;
    
public:
    TableSerializer(const Table& table);

    void load() override;

};

#endif