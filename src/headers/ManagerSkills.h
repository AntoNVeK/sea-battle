#ifndef MANAGERSKILLS_H
#define MANAGERSKILLS_H
#include <queue>
#include <memory>
#include <random>
#include <algorithm>
#include <typeinfo>
#include "Observer.h"
#include "NoSkillsException.h"
#include "ISkillFactory.h"
#include "AttackFactory.h"
#include "DoubleAttackFactory.h"
#include "ScannerFactory.h"
#include "skill_name.h"
#include "SkillFactory.h"

class ManagerSkills : public Observer
{
private:
    std::queue<std::shared_ptr<ISkillFactory>> skills;

    SkillFactory skillfactory;
public:

    ManagerSkills(SkillFactory& skillfactory);

    std::shared_ptr<ISkillFactory> GetFront();
    
    void accept() override;

    ManagerSkills(const ManagerSkills &other);
    ManagerSkills(ManagerSkills &&other);


    ManagerSkills& operator=(const ManagerSkills &other);
    ManagerSkills& operator=(ManagerSkills &&other);

    SkillName GetNameFrontSkill() const;

    void add_skill();

    void delete_skill();

    std::vector<std::string> GetQueueName() const;
    
    void clear();

    void add_skill(std::string skillname);
};



#endif