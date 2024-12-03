#include "../headers/ManagerSkills.h"


ManagerSkills::ManagerSkills(SkillFactory& skillfactory) : skillfactory(skillfactory)
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


ManagerSkills::ManagerSkills(const ManagerSkills &other) : skillfactory(other.skillfactory)
{
    this->skills = other.skills;
}



ManagerSkills::ManagerSkills(ManagerSkills &&other) : skillfactory(other.skillfactory)
{
    this->skills = std::move(other.skills);
}



ManagerSkills& ManagerSkills::operator=(const ManagerSkills &other)
{
    if (this != &other)
    {
        this->skillfactory = other.skillfactory;
        this->skills = other.skills;
    }
    return *this;
}
ManagerSkills& ManagerSkills::operator=(ManagerSkills &&other)
{
    if (this != &other)
    {
        this->skillfactory = other.skillfactory;
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
    return skill;
}



SkillName ManagerSkills::GetNameFrontSkill() const
{
    if (!skills.empty())
        return skills.front()->GetName();
    else
        SkillName::UNKNOWN;
}


void ManagerSkills::delete_skill()
{
    skills.pop();
}

std::vector<std::string> ManagerSkills::GetQueueName() const
{
    std::queue<std::shared_ptr<ISkillFactory>> tempQueue = skills;
    std::vector<std::string> res;

    while (!tempQueue.empty()) {
        switch (tempQueue.front().get()->GetName())
        {
        case SkillName::Attack:
            res.push_back("Attack");    
            break;
        case SkillName::DoubleAttack:
            res.push_back("DoubleAttack");    
            break;
        case SkillName::Scanner:
            res.push_back("Scanner");    
            break;
        default:
            break;
        }

        tempQueue.pop();
    }

    return res;
}


void ManagerSkills::clear()
{
    while (!skills.empty()) {
        skills.pop();
    }
}


void ManagerSkills::add_skill(std::string skillname)
{
    
    
    if(skillname == "Attack"){
        skills.push(skillfactory.get_factory(SkillName::Attack));
    }
    if(skillname == "DoubleAttack"){
        skills.push(skillfactory.get_factory(SkillName::DoubleAttack));   
    }
    if(skillname == "Scanner"){
        skills.push(skillfactory.get_factory(SkillName::Scanner));   
    }

}