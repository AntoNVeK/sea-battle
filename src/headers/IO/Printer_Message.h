#ifndef PRINTER_MESSAGE_H
#define PRINTER_MESSAGE_H
#include <iostream>
#include <utility>
#include "../game.h"

class Printer_Message
{
public:
    void attackMessage(Game &game);
    void printJson(Game &game);
    void applyAbility(Game &game);
    void nextAbility(Game &game);
    void getAbility(Game &game);
    void help();
};

#endif