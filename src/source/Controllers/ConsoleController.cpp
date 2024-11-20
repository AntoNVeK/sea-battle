#include "../../headers/Controllers/ConsoleController.h"

ConsoleController::ConsoleController(Game& game) : game(game) {}

void ConsoleController::setMode() {
    int mode;
    std::cout << "Enter mode (1 for NEW, 2 for LOAD): ";
    std::cin >> mode;

    if (mode == 1) {
        game.SetModeStartGame(ModeStartGame::NEW);
    } else if (mode == 2) {
        game.SetModeStartGame(ModeStartGame::LOAD);
    } else {
        std::cout << "Invalid mode entered. Defaulting to NEW mode.\n";
        game.SetModeStartGame(ModeStartGame::NEW);
    }
}



void ConsoleController::setFilename()
{
    std::string filename;
    std::cout << "Print filename: ";
    std::cin >> filename;

    game.SetFilename(filename);
    
}


void ConsoleController::setPlaceship()
{
    Length len = game.GetShipNeedPlacement().GetLen();

    int x, y, orientation;


    std::cout << "Print coord and orientation for ship len " << len << ": (x, y, orientation(0 : horizontical 1 : vertical))\n";

    std::cin >> x >> y >> orientation;

    game.SetPlaceShip({x, y}, (Orientation)orientation);

}