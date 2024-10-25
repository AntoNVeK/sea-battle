#include "../headers/skill_name.h"

namespace std
{

std::ostream&
operator<<(std::ostream& os, const SkillName &sn)
{
    switch (sn)
    {
    case SkillName::DoubleAttack:
        os << "DoubleAttack";
        break;
    
    case SkillName::Attack:
        os << "Attack";
        break;
    
    case SkillName::Scanner:
        os << "Scanner";
        break;
    
    default:
        throw std::logic_error("Bad skill name");

    }

    return os;

}
    
} // namespace std


