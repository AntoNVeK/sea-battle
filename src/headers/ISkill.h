#ifndef ISKILL_H
#define ISKILL_H
#include <functional>
#include "ScannerResult.h"


class Table;
class Coord;

class ISkill
{

public:

    virtual void use(Table& table) = 0;

    virtual void install_reaction(std::function<void(ScannerResult state)> func) = 0;

    virtual ~ISkill() = 0;

};



#endif