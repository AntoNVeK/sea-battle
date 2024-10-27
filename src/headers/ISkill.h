#ifndef ISKILL_H
#define ISKILL_H
#include <functional>
#include "SkillResult.h"

class ISkill
{

public:

    virtual void use() = 0;

    virtual ~ISkill() = 0;

};



#endif