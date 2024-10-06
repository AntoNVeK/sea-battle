#ifndef ISKILL_H
#define ISKILL_H




class Table;
class Coord;

class ISkill
{
public:
    virtual void use(Table& table) = 0;

    virtual void use(Table& table, const Coord& coord) = 0;

    virtual void use(Table& table, int x, int y) = 0;

    virtual ~ISkill() {};
};



#endif