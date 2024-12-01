#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H
#include <iostream>
#include "Input.h"
#include "../Game.h"
#include "ConsolePrinterMessage.h"

class ConsoleInput : public Input
{
private:
    Game& game;

public:

    ConsoleInput(Game& game);

    int setMode() override;

    std::string setFilename() override;

    std::vector<int> setPlaceship(int len_ship) override;
    
    int setNumberMove() override;

    Coord setCoord() override;

    void Endgame() override;

    std::string input() override;

    ~ConsoleInput() override = default;
    
};




#endif