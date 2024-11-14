#include "../headers/SkillFactory.h"


SkillFactory::SkillFactory(SkillResult& results, GetCoord& command, Table& table, ManagerShips& manager, Shooter& shooter) : results(results), command(command), table(table), manager(manager), shooter(shooter)
{
    this->_double_attack_factory = std::make_shared<DoubleAttackFactory>(results, shooter);
    this->_attack_factory = std::make_shared<AttackFactory>(manager);
    this->_scanner_factory = std::make_shared<ScannerFactory>(results, command, table);
    
}


SkillFactory::SkillFactory(const SkillFactory &other)
    : _double_attack_factory(other._double_attack_factory), 
      _attack_factory(other._attack_factory), 
      _scanner_factory(other._scanner_factory),
      results(other.results),
      table(other.table),
      manager(other.manager),
      shooter(other.shooter),
      command(command)
{    }

SkillFactory::SkillFactory(SkillFactory &&other)
    : _double_attack_factory(std::move(other._double_attack_factory)), 
      _attack_factory(std::move(other._attack_factory)), 
      _scanner_factory(std::move(other._scanner_factory)),
      results(other.results),
      table(other.table),
      manager(other.manager),
      shooter(other.shooter),
      command(command)
{    }


SkillFactory& SkillFactory::operator=(const SkillFactory &other)
{
    if (this == &other)
    {
        this->_double_attack_factory = other._double_attack_factory;
        this->_attack_factory = other._attack_factory;
        this->_scanner_factory = other._scanner_factory;
        this->results = other.results;
        this->table = other.table;
        this->manager = other.manager;
    }
    return *this;
}

SkillFactory& SkillFactory::operator=(SkillFactory &&other)
{
    if (this == &other)
    {
        this->_double_attack_factory = std::move(other._double_attack_factory);
        this->_attack_factory = std::move(other._attack_factory);
        this->_scanner_factory = std::move(other._scanner_factory);
        this->results = other.results;
        this->table = other.table;
        this->manager = other.manager;
    }
    return *this;
}


std::shared_ptr<ISkillFactory> SkillFactory::get_factory(SkillName _sn) const 
{
    switch (_sn)
    {
        case SkillName::DoubleAttack:
            return this->_double_attack_factory;

        case SkillName::Attack:
            return this->_attack_factory;

        case SkillName::Scanner:
            return this->_scanner_factory;
        
        default:
            throw std::logic_error("bad skill name");

    }

}



