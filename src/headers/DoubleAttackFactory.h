#ifndef DOUBLEATTACKFACTORY_H
#define DOUBLEATTACKFACTORY_H
#include "ISkillFactory.h"
#include "DoubleAttack.h"

class DoubleAttackFactory : public ISkillFactory
{
public:

    std::shared_ptr<ISkill> create(int x = 0, int y = 0) override;

    std::string GetName() const override;

    ~DoubleAttackFactory() override = default;

};




#endif