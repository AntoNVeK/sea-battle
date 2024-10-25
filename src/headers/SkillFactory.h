
#ifndef SKILLFACTORY_H
#define SKILLFACTORY_H

#include "ISkillFactory.h"
#include "DoubleAttackFactory.h"
#include "AttackFactory.h"
#include "ScannerFactory.h"
#include "skill_name.h"



class SkillFactory
{
public:
    SkillFactory(SkillResult& results);

    SkillFactory(const SkillFactory &other);
    SkillFactory(SkillFactory &&other);

    ~SkillFactory() = default;

    SkillFactory& operator=(const SkillFactory &other);
    SkillFactory& operator=(SkillFactory &&other);

    std::shared_ptr<ISkillFactory> get_factory(SkillName _sn) const;

private:
    std::shared_ptr<DoubleAttackFactory> _double_hit_factory;
    std::shared_ptr<AttackFactory> _rocket_attack_factory;
    std::shared_ptr<ScannerFactory> _scanner_factory;

    SkillResult& results;
};




#endif