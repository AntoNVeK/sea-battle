#include "../headers/Game.h"

Game::Game(SetFileNameCommand& set_file_name, SetModeCommand& set_mode, SetCoordCommand& set_coord, SetPlaceShipCommand& set_place_ship, EndGameCommand& end_game, PrintMessageCommand& print_message_command)
    : set_file_name(set_file_name),
      set_mode(set_mode),
      set_coord(set_coord),
      set_place_ship(set_place_ship),
      end_game(end_game),
      print_message_command(print_message_command),
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

    bool valid = false;
    while (!valid)
    {
        print_message_command.execute("Enter mode (1 for NEW, 2 for LOAD): \n");
        int mode = set_mode.execute();

        switch ((ModeStartGame)mode) {
            case ModeStartGame::NEW:
            {
                start_new_game();
                valid = true;
                break;
            }
            case ModeStartGame::LOAD:
            {
                if (load_game())
                {
                    valid = true;
                }

                break;
            }
            default:
                std::cerr << "Error: Mode not set.\n";
                break;
        }
    }
}

bool Game::load_game()
{
    std::string filename = set_file_name.execute();

    try
    {
        state.loadGame(filename);
        init_attack_coord_bot();
        return true;
    }
    catch(const std::runtime_error& e)
    {
        print_message_command.execute(std::string(e.what())  + "\n");
    }

    return false;
    


}


void Game::save_game()
{

    std::string filename = set_file_name.execute();
    try
    {
        state.saveGame(filename);
    }
    catch(const std::runtime_error& e)
    {
        print_message_command.execute(std::string(e.what())  + "\n");
    }
    

}


void Game::start_new_game()
{
    
    placePlayerShips();
    placeEnemyShips();
}

void Game::placePlayerShips()
{
    ShipManager_Player = ManagerShips({FOUR, THREE, THREE, TWO, TWO, TWO, ONE, ONE, ONE, ONE});
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
        
    }

    init_attack_coord_bot();

    
}


void Game::init_attack_coord_bot()
{
    attack_coord_bot = {};
    for (int j = 1; j <= Table_Player.GetY(); j++)
    {
        for (int i = 1; i <= Table_Player.GetX(); i++)
        {
            attack_coord_bot.push_back({i, j});
            if (Table_Player.GetCoords()[j - 1][i - 1] == SHIP && Table_Player.GetStateSegmentShip(i, j) == FULL)
                attack_coord_bot.push_back({i, j});
        }
    }
}



void Game::placeEnemyShips()
{

    ShipManager_Enemy = ManagerShips({FOUR, THREE, THREE, TWO, TWO, TWO, ONE, ONE, ONE, ONE});
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

    
}





void Game::check_win_player()
{
    if (ShipManager_Enemy.all_destroyed_ships())
    {
        print_message_command.execute("Enter mode (1 for NEW, 2 for END): \n");
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
}

void Game::check_win_bot()
{
    if (ShipManager_Player.all_destroyed_ships())
    {
        print_message_command.execute("Enter mode (1 for NEW, 2 for END): \n");
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

    
    
    
}

void Game::computer_attack()
{

    bool was_attack = false;

    while (!was_attack)
    {
        Coord coord = attack_coord_bot[rand() % attack_coord_bot.size()];
    
        try
        {
            last_attack_result = Table_Player.shoot(coord);
            auto it = std::find(attack_coord_bot.begin(), attack_coord_bot.end(), coord);


            if (it != attack_coord_bot.end()) {
                attack_coord_bot.erase(it);
            }

            was_attack = true;
        }
        catch(const std::exception& e)
        {
            
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

        skill->use();

        if (!results.empty())
        {
            print_message_command.execute(results.GetLast() + "\n");
            results.pop();
        }
        Manager_Skills.delete_skill();

        skillcoord = Coord();
    }
    catch(const NoSkillsException& e)
    {
        std::cerr << e.what() << '\n';
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


void Game::swap()
{
    if (current_player == Player::User)
        current_player = Player::Bot;
    else
        current_player = Player::User;
}

void Game::EndGame()
{
    end_game.execute();
}