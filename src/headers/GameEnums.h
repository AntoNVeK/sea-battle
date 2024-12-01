#ifndef GAME_ENUMS_H
#define GAME_ENUMS_H

#include <ostream>

enum class ModeStartGame : char
{
    UNKNOWN,
    NEW,
    LOAD
};

enum class Player : char
{
    User,
    Bot
};



#endif