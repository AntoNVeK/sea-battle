#ifndef DOUBLEATTACK_H
#define DOUBLEATTACK_H
#include "Table.h"
#include "Coord.h"
#include "ISkill.h"
#include "skill_name.h"


class DoubleAttack : public ISkill
{
public:
    DoubleAttack(Coord coord, SkillResult& results, Table& table);

    void use() override;

    ~DoubleAttack() override = default;

private:
    Table& table;

    Coord coord;

    SkillResult& results;
};


#endif