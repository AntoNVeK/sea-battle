#ifndef DOUBLEATTACK_H
#define DOUBLEATTACK_H
#include "Table.h"
#include "Coord.h"
#include "ISkill.h"

class DoubleAttack : public ISkill
{
public:
    DoubleAttack(int x, int y);

    void use(Table& table) override;

    void install_reaction(std::function<void()> func) override;

    ~DoubleAttack() override = default;

private:

    int _x;
    int _y;
};


#endif