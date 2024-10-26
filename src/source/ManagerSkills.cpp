#include "../headers/ManagerSkills.h"


ManagerSkills::ManagerSkills(std::shared_ptr<Command> command) : skillfactory(results, command)
{
    std::vector<SkillName> _set_skills = {
        SkillName::DoubleAttack,
        SkillName::Attack,
        SkillName::Scanner
    };
    srand(time(NULL));
    std::random_shuffle(_set_skills.begin(), _set_skills.end());

    for (const auto& skillname : _set_skills) {
        skills.push(skillfactory.get_factory(skillname));
    }
}


ManagerSkills::ManagerSkills(const ManagerSkills &other) : results(other.results), skillfactory(other.skillfactory)
{
    this->skills = other.skills;
}



ManagerSkills::ManagerSkills(ManagerSkills &&other) : results(other.results), skillfactory(other.skillfactory)
{
    this->skills = std::move(other.skills);
}



ManagerSkills& ManagerSkills::operator=(const ManagerSkills &other)
{
    if (this != &other)
    {
        this->skillfactory = other.skillfactory;
        this->results = other.results;
        this->skills = other.skills;
    }
    return *this;
}
ManagerSkills& ManagerSkills::operator=(ManagerSkills &&other)
{
    if (this != &other)
    {
        this->skillfactory = other.skillfactory;
        this->results = other.results;
        this->skills = std::move(other.skills);
    }
    return *this;
}




void ManagerSkills::add_skill()
{
    std::vector<SkillName> _set_skills = {
        SkillName::DoubleAttack,
        SkillName::Attack,
        SkillName::Scanner
    };

    srand(time(NULL));

    skills.push(skillfactory.get_factory(_set_skills[rand() % 3]));

}




void ManagerSkills::accept()
{
    this->add_skill();
}



std::shared_ptr<ISkillFactory> ManagerSkills::GetFront()
{
    if (skills.empty())
    {
        throw NoSkillsException("skill hasn't");
    }
    std::shared_ptr<ISkillFactory> skill = skills.front();
    skills.pop();
    return skill;
}



SkillName ManagerSkills::GetNameFrontSkill() const
{
    return skills.front()->GetName();
}


SkillResult& ManagerSkills::GetResults()
{
    return results;
}

