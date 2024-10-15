#ifndef ATTACKFACTORY_H
#define ATTACKFACTORY_H
#include "ISkillFactory.h"

class AttackFactory : public ISkillFactory
{
public:

    ISkill* create() override;

    ISkill* create(int x, int y) override;

    std::string& GetName() const override;

    ~AttackFactory() override = default;

};



#endif