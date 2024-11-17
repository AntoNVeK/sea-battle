#ifndef MANAGER_SKILLS_LOADER_H
#define MANAGER_SKILLS_LOADER_H
#include "Loader.h"
#include "../ManagerSkills.h"

class ManagerSkillsLoader : public Loader
{

private:
    ManagerSkills& manager;
    
public:
    ManagerSkillsLoader(ManagerSkills& manager);

    void loadFromJson(const json& j) override;

};

#endif