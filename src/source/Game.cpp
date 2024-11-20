#include "../headers/Game.h"

Game::Game(Commands& commands) 
    : commands(commands),
      Table_Player(), Table_Enemy(),
      ShipManager_Player({ONE}), ShipManager_Enemy({ONE}),
      results(), skillcoord(), shooter(Table_Enemy),
      command(skillcoord),
      skillfactory(results, command, Table_Enemy, ShipManager_Enemy, shooter),
      Manager_Skills(skillfactory),
      state(Table_Player, Table_Enemy, ShipManager_Player, ShipManager_Enemy, Manager_Skills, results, shooter),
      ship(ShipManager_Player[0])
      {
        
    mode = ModeStartGame::UNKNOWN;

    //Table_Enemy.AddObserver(&Manager_Skills);
    //Table_Enemy.AddObserver(&ShipManager_Enemy);
    //Table_Player.AddObserver(&ShipManager_Player);
    
}

void Game::play() {
    commands.set_mode();

    if (mode == ModeStartGame::NEW) {
        
        start_new_game();
        
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
    state.loadGame(this->filename);
    print(Table_Player);

    this->filename = "";
}


void Game::save_game()
{

}


void Game::SetFilename(std::string filename)
{
    this->filename = filename;
}

void Game::SetPlaceShip(Coord coord, Orientation orientation)
{
    coord_place_ship = coord;
    orientation_place_ship = orientation;
}

const Ship& Game::GetShipNeedPlacement() const
{
    return ship;
}

void Game::start_new_game()
{
    for (int i = 0; i < ShipManager_Player.GetCountShips(); i++)
    {
        ship = ShipManager_Player[i];
        

        while (true)
        {
            orientation_place_ship = Orientation::UNDEFINE;
            coord_place_ship = Coord();
            commands.set_placeship();
            
            if (coord_place_ship.GetX() < 1 || coord_place_ship.GetY() < 1 || coord_place_ship.GetX() > Table_Player.GetX() || coord_place_ship.GetY() > Table_Player.GetY() || orientation_place_ship == Orientation::UNDEFINE)
            {
                continue;
            }

            try
            {
                ship.SetOrientation(orientation_place_ship);
                Table_Player.add_ship(ship, coord_place_ship);
                break;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;

            }
        }
    }

    print(Table_Player);
    
    placeEnemyShips();
}

void Game::placeEnemyShips()
{
    
    for (int i = 0; i < ShipManager_Enemy.GetCountShips(); i++)
    {
        while(true)
        {
            try
            {
                int x = rand() % (Table_Enemy.GetX());
                int y = rand() % (Table_Enemy.GetY());
                ship = ShipManager_Enemy[i];
                ship.SetOrientation((Orientation)(rand() % 2));
                Table_Enemy.add_ship(ship, {x,y});
                break;
            }
            catch(const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }

        }
    }
    print(Table_Enemy);
}

