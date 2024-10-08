#ifndef NO_SKILLS_EXCEPTION
#define NO_SKILLS_EXCEPTION
#include "GameException.h"


class NoSkillsException : public GameException
{
    explicit NoSkillsException(const std::string& msg) : GameException(msg) {}
};



#endif