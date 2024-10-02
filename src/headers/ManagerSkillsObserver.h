#ifndef MANAGERSKILLSOBSERVER_H
#define MANAGERSKILLSOBSERVER_H
#include "ManagerSkills.h"

class ManagerSkillsObserver
{
private:
    ManagerSkills& manager;

public:
    void accept();
    
    ManagerSkillsObserver(const ManagerSkillsObserver &other);
    ManagerSkillsObserver(ManagerSkillsObserver &&other);


    ManagerSkillsObserver& operator=(const ManagerSkillsObserver &other);
    ManagerSkillsObserver& operator=(ManagerSkillsObserver &&other);



    ~ManagerSkillsObserver(){};
};

#endif