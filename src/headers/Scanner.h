#ifndef SCANNER_H
#define SCANNER_H
#include "Table.h"
#include "Coord.h"



class Scanner : public ISkill
{
public:
    Scanner();

    void use(Table& table) override;

    void use(Table& table, int x, int y) override;

    void use(Table& table, const Coord& coord) override;

};





#endif