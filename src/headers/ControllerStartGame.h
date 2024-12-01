#ifndef CONTROLLERSTARTGAME_H
#define CONTROLLERSTARTGAME_H
#include <iostream>
#include "Input.h"
#include "./IO/ConsolePrinterMessage.h"


class Game;

class ControllerStartGame
{
private:
    Game& game;

public:

    ControllerStartGame(Game& game);

    int setMode();

    std::string setFilename();

    std::vector<int> setPlaceship(int len_ship);
    
    int setNumberMove();

    Coord setCoord();

    void Endgame();

    ~ControllerStartGame() = default;
    
};




#endif