#ifndef OUT_OF_BOUNDS_EXCEPTION
#define OUT_OF_BOUNDS_EXCEPTION
#include "GameException.h"


class OutOfBoundsException : public GameException
{
public:
    OutOfBoundsException(const std::string& msg);
};


#endif