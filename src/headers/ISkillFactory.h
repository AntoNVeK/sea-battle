#ifndef ISKILLFACTORY_H
#define ISKILLFACTORY_H
#include "ISkill.h"
#include <string>
#include <memory>

class ISkillFactory
{

public:

    virtual std::shared_ptr<ISkill> create(int x = 0, int y = 0) = 0;

    virtual std::string GetName() const = 0;

    virtual ~ISkillFactory() = 0;

};

#endif