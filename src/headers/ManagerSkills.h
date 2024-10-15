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


class ManagerSkills : public Observer
{
private:
    std::queue<std::shared_ptr<ISkillFactory>> skills;
public:

    ManagerSkills();

    std::shared_ptr<ISkillFactory> GetFront();
    
    void accept() override;

    ManagerSkills(const ManagerSkills &other);
    ManagerSkills(ManagerSkills &&other);


    ManagerSkills& operator=(const ManagerSkills &other);
    ManagerSkills& operator=(ManagerSkills &&other);

    

    void add_skill();
};



#endif