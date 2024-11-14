#ifndef TABLE_SERIALIZER_H
#define TABLE_SERIALIZER_H
#include "Serializer.h"
#include "Table.h"

class TableSerializer : public Serializer
{

private:
    Table& table;
    
public:
    TableSerializer(Table& table);

    void load() override;

};

#endif