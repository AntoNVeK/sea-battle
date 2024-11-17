#include "../../headers/Loaders/ManagerSkillsLoader.h"


ManagerSkillsLoader::ManagerSkillsLoader(ManagerSkills& manager) : manager(manager)
{}

void ManagerSkillsLoader::loadFromJson(const json& j)
{
    manager.clear();
    for (const auto& skill : j["Manager_Skills"]["skills"]) {
        manager.add_skill(skill);
    }
}
