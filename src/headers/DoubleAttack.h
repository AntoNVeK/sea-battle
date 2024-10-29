#ifndef DOUBLEATTACK_H
#define DOUBLEATTACK_H
#include "Table.h"
#include "Coord.h"
#include "ISkill.h"
#include "skill_name.h"
#include "Shooter.h"

class DoubleAttack : public ISkill
{
public:
    DoubleAttack(SkillResult& results, Shooter& shooter);

    void use() override;

    ~DoubleAttack() override = default;

private:
    SkillResult& results;

    Shooter& shooter;
};


#endif