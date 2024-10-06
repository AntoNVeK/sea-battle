#ifndef MANAGERSKILLSOBSERVER_H
#define MANAGERSKILLSOBSERVER_H
#include "ManagerSkills.h"
#include "Table.h"

class ManagerSkills;

class ManagerSkillsObserver
{
private:
    ManagerSkills& manager;

public:
    ManagerSkillsObserver(ManagerSkills& manager);

    void accept();
    

    ManagerSkillsObserver(const ManagerSkillsObserver &other);
    ManagerSkillsObserver(ManagerSkillsObserver &&other);


    ManagerSkillsObserver& operator=(const ManagerSkillsObserver &other);
    ManagerSkillsObserver& operator=(ManagerSkillsObserver &&other);



    ~ManagerSkillsObserver(){};
};

#endif