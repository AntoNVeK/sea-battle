#ifndef ISKILLFACTORY_H
#define ISKILLFACTORY_H
#include "ISkill.h"
#include <string>
#include <memory>
#include "skill_name.h"

class ISkillFactory
{

public:

    virtual std::shared_ptr<ISkill> create() = 0;

    virtual SkillName GetName() const = 0;

    virtual ~ISkillFactory() = 0;

};

#endif