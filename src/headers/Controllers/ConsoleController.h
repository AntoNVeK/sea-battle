#ifndef CONSOLE_CONTROLLER_H
#define CONSOLE_CONTROLLER_H
#include <iostream>
#include "Controller.h"
#include "../Game.h"


class ConsoleController : public Controller
{
private:
    Game& game;

public:

    ConsoleController(Game& game);

    void setMode() override;

    void setFilename() override;

    void setPlaceship() override;
    
    void setNumberMove() override;

    void setPlayerAttack() override;

    void setSkillCoord() override;

    void setModeEnd() override;

    void Endgame() override;

    ~ConsoleController() override = default;
    
};




#endif