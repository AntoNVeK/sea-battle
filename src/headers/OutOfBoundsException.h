#ifndef OUT_OF_BOUNDS_EXCEPTION_H
#define OUT_OF_BOUNDS_EXCEPTION_H
#include "GameException.h"


class OutOfBoundsException : public GameException
{
public:
    OutOfBoundsException(const std::string& msg);
};


#endif