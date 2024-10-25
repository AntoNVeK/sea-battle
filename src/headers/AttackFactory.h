#ifndef ATTACKFACTORY_H
#define ATTACKFACTORY_H
#include "ISkillFactory.h"
#include "Attack.h"
#include "SkillResult.h"



class AttackFactory : public ISkillFactory
{
public:
    AttackFactory(SkillResult& results);
    
    std::shared_ptr<ISkill> create(Coord coord) override;

    SkillName GetName() const override;

    ~AttackFactory() override = default;
private:
    SkillResult& results;
};



#endif