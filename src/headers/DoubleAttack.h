#ifndef DOUBLEATTACK_H
#define DOUBLEATTACK_H
#include "Table.h"
#include "Coord.h"
#include "ISkill.h"
#include "skill_name.h"


class DoubleAttack : public ISkill
{
public:
    DoubleAttack(Coord coord, SkillResult& results);

    void use(Table& table) override;

    ~DoubleAttack() override = default;

private:

    Coord coord;

    SkillResult& results;
};


#endif