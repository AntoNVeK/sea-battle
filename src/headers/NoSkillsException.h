#ifndef NO_SKILLS_EXCEPTION
#define NO_SKILLS_EXCEPTION
#include "GameException.h"


class NoSkillsException : public GameException
{
public:
    explicit NoSkillsException(const std::string& msg);
};



#endif