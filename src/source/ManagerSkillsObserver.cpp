#include "../headers/ManagerSkillsObserver.h"


ManagerSkillsObserver::ManagerSkillsObserver(ManagerSkills& manager) : manager(manager)
{}



void ManagerSkillsObserver::accept()
{
    manager.add_skill();
}




ManagerSkillsObserver::ManagerSkillsObserver(const ManagerSkillsObserver &other) : manager(other.manager)
{
}



ManagerSkillsObserver::ManagerSkillsObserver(ManagerSkillsObserver &&other) : manager(other.manager)
{
}




ManagerSkillsObserver& ManagerSkillsObserver::operator=(const ManagerSkillsObserver &other)
{
    if (this != &other)
    {
        this->manager = other.manager;
    }
    return *this;
}
ManagerSkillsObserver& ManagerSkillsObserver::operator=(ManagerSkillsObserver &&other)
{
    if (this != &other)
    {
        this->manager = other.manager;
    }
    return *this;
}