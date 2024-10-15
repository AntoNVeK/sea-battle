#ifndef DOUBLEATTACKFACTORY_H
#define DOUBLEATTACKFACTORY_H
#include "ISkillFactory.h"

class DoubleAttackFactory : public ISkillFactory
{
public:

    ISkill* create() override;

    ISkill* create(int x, int y) override;

    std::string& GetName() const override;

    ~DoubleAttackFactory() override = default;

};




#endif