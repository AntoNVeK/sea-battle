#ifndef NO_SKILLS_EXCEPTION_H
#define NO_SKILLS_EXCEPTION_H
#include "GameException.h"


class NoSkillsException : public GameException
{
public:
    explicit NoSkillsException(const std::string& msg);
};



#endif