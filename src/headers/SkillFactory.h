#ifndef SKILLFACTORY_H
#define SKILLFACTORY_H

#include "ISkillFactory.h"
#include "DoubleAttackFactory.h"
#include "AttackFactory.h"
#include "ScannerFactory.h"
#include "skill_name.h"
#include "GetCoord.h"
#include "Shooter.h"

class SkillFactory
{
public:
    SkillFactory(SkillResult& results, GetCoord& command, Table& table, ManagerShips& manager, Shooter& shooter);

    SkillFactory(const SkillFactory &other);
    SkillFactory(SkillFactory &&other);

    ~SkillFactory() = default;

    SkillFactory& operator=(const SkillFactory &other);
    SkillFactory& operator=(SkillFactory &&other);

    std::shared_ptr<ISkillFactory> get_factory(SkillName _sn) const;
    

private:
    std::shared_ptr<DoubleAttackFactory> _double_attack_factory;
    std::shared_ptr<AttackFactory> _attack_factory;
    std::shared_ptr<ScannerFactory> _scanner_factory;

    SkillResult& results;

    GetCoord& command;

    Table& table;

    ManagerShips& manager;

    Shooter& shooter;
};




#endif