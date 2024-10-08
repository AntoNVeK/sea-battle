#ifndef SHIP_PLACE_EXCEPTION
#define SHIP_PLACE_EXCEPTION
#include "GameException.h"



class ShipPlacementException : public GameException
{
public:
    explicit ShipPlacementException(const std::string& msg);
};








#endif