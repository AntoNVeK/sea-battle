#ifndef ATTACKFACTORY_H
#define ATTACKFACTORY_H
#include "ISkillFactory.h"
#include "Attack.h"

class AttackFactory : public ISkillFactory
{
public:

    

    std::shared_ptr<ISkill> create(int x = 0, int y = 0) override;

    std::string GetName() const override;

    ~AttackFactory() override = default;

};



#endif