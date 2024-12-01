#include "../headers/Game.h"

Game::Game(SetFileNameCommand& set_file_name, SetModeCommand& set_mode, SetCoordCommand& set_coord, SetPlaceShipCommand& set_place_ship, EndGameCommand& end_game)
    : set_file_name(set_file_name),
      set_mode(set_mode),
      set_coord(set_coord),
      set_place_ship(set_place_ship),
      end_game(end_game),
      Table_Player(), Table_Enemy(),
      ShipManager_Player({FOUR}), ShipManager_Enemy({FOUR}),
      results(), skillcoord(), shooter(Table_Enemy),
      command(skillcoord),
      skillfactory(results, command, Table_Enemy, ShipManager_Enemy, shooter),
      Manager_Skills(skillfactory),
      state(Table_Player, Table_Enemy, ShipManager_Player, ShipManager_Enemy, Manager_Skills, shooter)
      {
        
    
    
    
}

void Game::play() {

    std::cout << "Enter mode (1 for NEW, 2 for LOAD): ";
    int mode = set_mode.execute();

    switch ((ModeStartGame)mode) {
        case ModeStartGame::NEW:
            start_new_game();
            break;
        case ModeStartGame::LOAD:
            load_game();
            break;
        default:
            std::cerr << "Error: Mode not set.\n";
            break;
    }
}

void Game::load_game()
{
    std::string filename = set_file_name.execute();

    state.loadGame(filename);



    print(Table_Player, true);
    print(Table_Enemy, false);
}


void Game::save_game()
{

    std::string filename = set_file_name.execute();

    state.saveGame(filename);

}


void Game::start_new_game()
{
    
    placePlayerShips();
    placeEnemyShips();
}

void Game::placePlayerShips()
{
    ShipManager_Player = ManagerShips({FOUR});
    Table_Player = Table();

    for (int i = 0; i < ShipManager_Player.GetCountShips(); i++)
    {


        while (true)
        {
            Coord coord_place_ship = Coord();
            Orientation orientation_place_ship = Orientation::UNDEFINE;
            std::vector<int> arr = set_place_ship.execute((int)ShipManager_Player[i].GetLen());
            
            coord_place_ship = Coord(arr[0], arr[1]);
            orientation_place_ship = (Orientation)arr[2];


            if (coord_place_ship.GetX() < 1 || coord_place_ship.GetY() < 1 || coord_place_ship.GetX() > Table_Player.GetX() || coord_place_ship.GetY() > Table_Player.GetY() || orientation_place_ship == Orientation::UNDEFINE)
            {
                continue;
            }

            try
            {
                ShipManager_Player[i].SetOrientation(orientation_place_ship);
                Table_Player.add_ship(ShipManager_Player[i], coord_place_ship);
                break;
            }
            catch (const ShipPlacementException &e)
            {
                std::cerr << e.what() << std::endl;

            }
        }
        print(Table_Player, true);
        
    }
}



void Game::placeEnemyShips()
{

    ShipManager_Enemy = ManagerShips({ONE});
    Table_Enemy = Table();
    Table_Enemy.AddObserver(&Manager_Skills);

    for (int i = 0; i < ShipManager_Enemy.GetCountShips(); i++)
    {
        while(true)
        {
            try
            {
                int x = rand() % (Table_Enemy.GetX());
                int y = rand() % (Table_Enemy.GetY());
                
                ShipManager_Enemy[i].SetOrientation((Orientation)(rand() % 2));
                Table_Enemy.add_ship(ShipManager_Enemy[i], {x,y});
                break;
            }
            catch(const ShipPlacementException &e)
            {
                
            }

        }
    }
    print(Table_Enemy, false);
    
}

void Game::print(Table& table, bool flag)
{
    if (flag)
        std::cout << "Player\n";
    else
        std::cout << "Enemy\n";
    CellState state = UNKNOWN;
    const std::vector<std::vector<CellState>>& vec = table.GetCoords();
    const std::set<Coord>& attack_elements = table.GetAttackCoords();
    for(int j = 0; j < table.GetY(); j++)
    {
        for(int i = 0; i < table.GetX(); i++){
            state = vec[j][i];
            if (flag || attack_elements.find(Coord(i + 1, j + 1)) != attack_elements.end())
            {
                
                if (state != SHIP)
                {
                    std::cout << static_cast<char>(state);
                }
                else
                {
                    std::cout << static_cast<char>(table.GetStateSegmentShip(i, j));
                }
            }
            else
            {
                std::cout << static_cast<char>(UNKNOWN);
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
}


void Game::check_end_game()
{
    if (ShipManager_Enemy.all_destroyed_ships())
    {
        std::cout << "Enter mode (1 for NEW, 2 for END): ";
        int mode = set_mode.execute();

        
        switch (mode)
        {
        case 1:
            placeEnemyShips();
            break;
        case 2:
            end_game.execute();
            break;
        default:
            break;
        }
    }
    if (ShipManager_Player.all_destroyed_ships())
    {
        int mode = set_mode.execute();
        

        switch (mode)
        {
        case 1:
            start_new_game();
            break;
        case 2:
            end_game.execute();
            break;
        default:
            break;
        }
    }
}




void Game::player_attack()
{
    Coord attack_coord = set_coord.execute();

    try
    {
        last_attack_result = shooter(attack_coord);
        attack_coord = Coord();
    }
    catch (const OutOfBoundsException &e)
    {
        std::cout << "Attack out of bounds exception\n";

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    print(Table_Enemy, false);
    
    
    
}

void Game::computer_attack()
{

    bool was_attack = false;

    while (!was_attack)
    {
        int x = rand() % (Table_Enemy.GetX());
        int y = rand() % (Table_Enemy.GetY());

        
        if ((Table_Player.GetCoords()[y][x] == SHIP && bot_attack_coords.find(Coord(x, y)) != bot_attack_coords.end()) || Table_Player.GetCoords()[y][x] != SHIP)
        {
            try
            {
                last_attack_result = Table_Player.shoot({x, y});
                bot_attack_coords.insert({x, y});

                was_attack = true;
            }
            catch(const std::exception& e)
            {
                
            }
        }
    }

    

}

void Game::use_skill()
{
    try
    {

        auto factory = Manager_Skills.GetFront();

        if (factory->GetName() == SkillName::Scanner)
        {
            skillcoord = set_coord.execute();
        }

        auto skill = factory->create();

        std::cout << factory->GetName() << "\n";

        skill->use();

        if (!results.empty())
        {
            std::cout << results.GetLast() << "\n";
            results.pop();
        }
        Manager_Skills.delete_skill();

        skillcoord = Coord();
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}



Table& Game::get_player_table()
{
    return Table_Player;
}

Table& Game::get_enemy_table()
{
    return Table_Enemy;
}

ManagerShips& Game::get_player_ships()
{
    return ShipManager_Player;
}
	
ManagerShips& Game::get_enemy_ships()
{
    return ShipManager_Enemy;
}