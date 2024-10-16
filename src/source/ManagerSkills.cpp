#include "../headers/ManagerSkills.h"


ManagerSkills::ManagerSkills()
{
    std::vector<std::shared_ptr<ISkillFactory>> vector_skills;
    vector_skills.push_back(std::make_shared<AttackFactory>());
    vector_skills.push_back(std::make_shared<ScannerFactory>());
    vector_skills.push_back(std::make_shared<DoubleAttackFactory>());

    srand(time(NULL));
    std::random_shuffle(vector_skills.begin(), vector_skills.end());

    for (const auto& skill : vector_skills) {
        skills.push(skill);
    }
}


ManagerSkills::ManagerSkills(const ManagerSkills &other)
{
    this->skills = other.skills;
}



ManagerSkills::ManagerSkills(ManagerSkills &&other)
{
    this->skills = std::move(other.skills);
}



ManagerSkills& ManagerSkills::operator=(const ManagerSkills &other)
{
    if (this != &other)
    {
        this->skills = other.skills;
    }
    return *this;
}
ManagerSkills& ManagerSkills::operator=(ManagerSkills &&other)
{
    if (this != &other)
    {
        this->skills = std::move(other.skills);
    }
    return *this;
}




void ManagerSkills::add_skill()
{
    std::vector<std::shared_ptr<ISkillFactory>> vector_skills;
    vector_skills.push_back(std::make_shared<ScannerFactory>());

    vector_skills.push_back(std::make_shared<AttackFactory>());

    vector_skills.push_back(std::make_shared<DoubleAttackFactory>());

    srand(time(NULL));

    skills.push(vector_skills[rand() % 3]);

}




void ManagerSkills::accept()
{
    this->add_skill();
}



std::shared_ptr<ISkillFactory> ManagerSkills::GetFront()
{
    std::shared_ptr<ISkillFactory> skill = skills.front();
    skills.pop();
    return skill;
}