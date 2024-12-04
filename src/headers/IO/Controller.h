#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>
#include <functional>
#include "ConsoleShow_Table.h"
#include "Printer_Message.h"
#include "../GameState.h"
#include "../Table.h"
#include "Printer_Table.h"
#include "View.h"
#include "../Game.h"
#include "Commands.h"
#include "IController.h"

template<typename Inputer, typename Printer_Table, typename Printer_Message>
class Controller : public IController 
{
private:
    Commands list_commands;
    Game &game;
    Inputer inputer;
    View<Printer_Table, Printer_Message> view;
    std::map<std::string, std::function<void()>> commands;
    bool isGameRunning = true;

public:
    Controller(Game &game) : game(game), inputer(list_commands), view(game, list_commands) { initialize_commands(); }
    
    void initialize_commands();
    
    virtual int setMode() override;

    std::string setFilename() override;

    std::vector<int> setPlaceship(int len_ship) override;

    Coord setCoord() override;

    void Endgame() override;

    void run() override;

    void print_message(std::string string) override;



};

#include "Controller.hpp"

#endif 