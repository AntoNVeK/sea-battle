#ifndef MANAGERSKILLS_H
#define MANAGERSKILLS_H
#include "ISkill.h"
#include <queue>
#include <memory>
#include <random>
#include <algorithm>
#include "DoubleAttack.h"
#include "Scanner.h"
#include "Attack.h"
#include <typeinfo>
#include "Observer.h"
#include "NoSkillsException.h"





class ManagerSkills : public Observer
{
private:
    std::queue<std::shared_ptr<ISkill>> skills;
public:

    ManagerSkills();

    std::shared_ptr<ISkill> GetFront();
    
    void accept() override;

    ManagerSkills(const ManagerSkills &other);
    ManagerSkills(ManagerSkills &&other);


    ManagerSkills& operator=(const ManagerSkills &other);
    ManagerSkills& operator=(ManagerSkills &&other);

    

    void add_skill();
};



#endif