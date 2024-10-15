#ifndef ISKILLFACTORY_H
#define ISKILLFACTORY_H
#include "ISkill.h"
#include <string>


class ISkillFactory
{

public:

    virtual ISkill* create() = 0;

    virtual ISkill* create(int x, int y) = 0;

    virtual std::string& GetName() const = 0;

    virtual ~ISkillFactory() = default;

};

#endif