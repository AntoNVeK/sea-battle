#include "../headers/Game.h"

Game::Game(Commands& commands) 
    : commands(commands),
      Table_Player(), Table_Enemy(),
      ShipManager_Player({ONE}), ShipManager_Enemy({ONE}),
      results(), skillcoord(), shooter(Table_Enemy),
      command(skillcoord),
      skillfactory(results, command, Table_Enemy, ShipManager_Enemy, shooter),
      Manager_Skills(skillfactory),
      state(Table_Player, Table_Enemy, ShipManager_Player, ShipManager_Enemy, Manager_Skills, results, shooter) 
      {
        
    mode = ModeStartGame::UNKNOWN;

    Table_Enemy.AddObserver(&Manager_Skills);
    Table_Enemy.AddObserver(&ShipManager_Enemy);
    Table_Player.AddObserver(&ShipManager_Player);
    
}

void Game::play() {
    commands.set_mode();

    if (mode == ModeStartGame::NEW) {
        std::cout << "Starting new game...\n";
        
    } else if (mode == ModeStartGame::LOAD) {
        commands.set_filename();
        load_game();
        
    } else {
        std::cerr << "Error: Mode not set. Exiting.\n";
    }
}

void Game::SetModeStartGame(ModeStartGame mode) {
    this->mode = mode;
}

void Game::load_game()
{
    //state.loadGame(this->filename);

    this->filename = "";
}


void Game::save_game()
{

}


void Game::SetFilename(std::string filename)
{
    this->filename = filename;
}

void Game::start_new_game()
{

}