#ifndef MANAGERSKILLS_H
#define MANAGERSKILLS_H
#include "ISkill.h"
#include <queue>

class ManagerSkills
{
private:
    std::queue<ISkill*> skills;
public:
    ManagerSkills();


    ManagerSkills(const ManagerSkills &other);
    ManagerSkills(ManagerSkills &&other);


    ManagerSkills& operator=(const ManagerSkills &other);
    ManagerSkills& operator=(ManagerSkills &&other);


    void add_skill();
};



#endif