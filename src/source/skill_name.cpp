#include "../headers/skill_name.h"

namespace std
{

std::ostream&
operator<<(std::ostream& os, const SkillName &sn)
{
    switch (sn)
    {
    case SkillName::DoubleAttack:
        os << "Next skill is DoubleAttack";
        break;
    
    case SkillName::Attack:
        os << "Next skill is Attack";
        break;
    
    case SkillName::Scanner:
        os << "Next skill is Scanner";
        break;
    
    case SkillName::UNKNOWN:
        os << "No abilities";
        break;

    }

    return os;

}
    
} // namespace std


