#ifndef ATTACKFACTORY_H
#define ATTACKFACTORY_H
#include "ISkillFactory.h"
#include "Attack.h"
#include "SkillResult.h"



class AttackFactory : public ISkillFactory
{
public:
    AttackFactory();
    
    std::shared_ptr<ISkill> create() override;

    SkillName GetName() const override;

    ~AttackFactory() override = default;

};



#endif