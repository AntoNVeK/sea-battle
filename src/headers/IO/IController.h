#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#include <iostream>
#include "Input.h"
#include "ConsolePrinterMessage.h"




class IController
{


public:

    virtual int setMode() = 0;

    virtual std::string setFilename() = 0;

    virtual std::vector<int> setPlaceship(int len_ship) = 0;

    virtual Coord setCoord() = 0;

    virtual void Endgame() = 0;

    virtual void run() = 0;

    virtual void print_message(std::string string) = 0;

    virtual ~IController() = 0;
    
};




#endif