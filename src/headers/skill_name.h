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

} // namespace std




#endif