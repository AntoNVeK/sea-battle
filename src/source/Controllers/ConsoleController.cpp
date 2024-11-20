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
