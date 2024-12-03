#ifndef SKILL_NAME_H
#define SKILL_NAME_H

#include <ostream>

enum class SkillName : char
{
    DoubleAttack = 'D',
    Attack = 'R',
    Scanner = 'S',
    UNKNOWN
};

namespace std
{
    
std::ostream& operator<<(std::ostream& os, const SkillName &sn);

inline std::string to_string(const SkillName &sn)
    {
        switch (sn)
        {
            case SkillName::DoubleAttack: return "Next skill is DoubleAttack";;
            case SkillName::Attack: return "Next skill is Attack";
            case SkillName::Scanner: return "Next skill is Scanner";
            case SkillName::UNKNOWN: return "No abilities";
            default: return "No abilities";
        }
    }
} // namespace std




#endif