#include "../headers/Game.h"

Game::Game(Command* set_mode_command) 
    : set_mode_command(set_mode_command),
      Table_Player(), Table_Enemy(),
      ShipManager_Player({ONE}), ShipManager_Enemy({ONE}),
      results(), skillcoord(), shooter(Table_Enemy),
      command(skillcoord),
      skillfactory(results, command, Table_Enemy, ShipManager_Enemy, shooter),
      Manager_Skills(skillfactory),
      state(Table_Player, Table_Enemy, ShipManager_Player, ShipManager_Enemy, Manager_Skills, results, shooter) {
    mode = ModeStartGame::UNKNOWN;
}

void Game::play() {
    set_mode_command->execute();

    if (mode == ModeStartGame::NEW) {
        std::cout << "Starting new game...\n";
        
    } else if (mode == ModeStartGame::LOAD) {
        std::cout << "Loading saved game...\n";
        
    } else {
        std::cerr << "Error: Mode not set. Exiting.\n";
    }
}

void Game::SetModeStartGame(ModeStartGame mode) {
    this->mode = mode;
}
