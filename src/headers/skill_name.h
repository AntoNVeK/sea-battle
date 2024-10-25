#pragma once


#ifndef _SKILL_NAME_H
#define _SKILL_NAME_H

#include <ostream>

enum class SkillName : char
{
    DoubleAttack = 'D',
    Attack = 'R',
    Scanner = 'S'
};

namespace std
{
    
std::ostream& operator<<(std::ostream& os, const SkillName &sn);

} // namespace std




#endif // _SKILL_NAME_H