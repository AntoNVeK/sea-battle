#ifndef SHIP_PLACE_EXCEPTION_H
#define SHIP_PLACE_EXCEPTION_H
#include "GameException.h"



class ShipPlacementException : public GameException
{
public:
    explicit ShipPlacementException(const std::string& msg);
};








#endif