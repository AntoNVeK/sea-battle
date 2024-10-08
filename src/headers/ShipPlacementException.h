#ifndef SHIP_PLACE_EXCEPTION
#define SHIP_PLACE_EXCEPTION
#include "GameException.h"



class ShipPlacementException : public GameException
{
    explicit ShipPlacementException(const std::string& msg) : GameException(msg) {}
};








#endif