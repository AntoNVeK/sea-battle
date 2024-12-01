#ifndef PRINTER_MESSAGE_H
#define PRINTER_MESSAGE_H
#include <iostream>
#include <utility>
#include "../game.h"
#include "ConsolePrinterMessage.h"
#include "Commands.h"
class Printer_Message
{
private:
    ConsolePrinterMessage printer;
    Commands& commands;
public:
    Printer_Message(Commands& commands) : commands(commands) {}
    void attackMessage(Game &game);
    void applyAbility(Game &game);
    void nextAbility(Game &game);
    void help();

};

#endif