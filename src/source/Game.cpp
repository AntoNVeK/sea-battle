#include "../headers/Game.h"

Game::Game(Commands& commands) 
    : commands(commands),
      Table_Player(), Table_Enemy(),
      ShipManager_Player({FOUR}), ShipManager_Enemy({FOUR, THREE, THREE, TWO, TWO, TWO, ONE, ONE, ONE, ONE}),
      results(), skillcoord(), shooter(Table_Enemy),
      command(skillcoord),
      skillfactory(results, command, Table_Enemy, ShipManager_Enemy, shooter),
      Manager_Skills(skillfactory),
      state(Table_Player, Table_Enemy, ShipManager_Player, ShipManager_Enemy, Manager_Skills, results, shooter),
      ship(ShipManager_Player[0])
      {
        
    mode = ModeStartGame::UNKNOWN;

    Table_Enemy.AddObserver(&Manager_Skills);
    
    
}

void Game::play() {
    commands.set_mode();

    switch (mode) {
        case ModeStartGame::NEW:
            start_new_game();
            break;
        case ModeStartGame::LOAD:
            load_game();
            break;
        default:
            std::cerr << "Error: Mode not set. Exiting.\n";
            break;
    }
}

void Game::SetModeStartGame(ModeStartGame mode) {
    this->mode = mode;
}

void Game::load_game()
{
    commands.set_filename();
    state.loadGame(this->filename);
    print(Table_Player);

    this->filename = "";
}


void Game::save_game()
{
    commands.set_filename();
    state.saveGame(this->filename);
    this->filename = "";
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
            catch (const ShipPlacementException &e)
            {
                std::cerr << e.what() << std::endl;

            }
        }
        print(Table_Player);
    }

    print(Table_Player);
    
    placeEnemyShips();
}

void Game::placeEnemyShips()
{
    
    for (int i = 0; i < ShipManager_Enemy.GetCountShips(); i++)
    {
        ship = ShipManager_Enemy[i];
        while(true)
        {
            try
            {
                int x = rand() % (Table_Enemy.GetX());
                int y = rand() % (Table_Enemy.GetY());
                
                ship.SetOrientation((Orientation)(rand() % 2));
                Table_Enemy.add_ship(ShipManager_Enemy[i], {x,y});
                break;
            }
            catch(const ShipPlacementException &e)
            {
                
            }

        }
    }
    print(Table_Enemy);
}

void Game::print(Table& table)
{
    CellState state = UNKNOWN;
    const std::vector<std::vector<CellState>>& vec = table.GetCoords();
    const std::set<Coord>& attack_elements = table.GetAttackCoords();
    for(int j = 0; j < table.GetY(); j++)
    {
        for(int i = 0; i < table.GetX(); i++){
            state = vec[j][i];
            //if (attack_elements.find(Coord(i + 1, j + 1)) != attack_elements.end())
            //{
            //    
                if (state != SHIP)
                {
                    std::cout << static_cast<char>(state);
                }
                else
                {
                    std::cout << static_cast<char>(table.GetStateSegmentShip(i, j));
                }
            //}
            //else
            //{
            //    std::cout << static_cast<char>(UNKNOWN);
            //}
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << " ______________________________________ \n";
}


void Game::check_end_game()
{
    if (ShipManager_Player.all_destroyed_ships())
    {
        commands.set_modeend();

        switch (mode_end)
        {
        case 1:
            start_new_game();
            break;
        case 2:
            commands.endgame();
            break;
        default:
            break;
        }
    }
    else if (ShipManager_Enemy.all_destroyed_ships())
    {
        switch (mode_end)
        {
        case 1:
            placeEnemyShips();
            break;
        case 2:
            commands.endgame();
            break;
        default:
            break;
        }
    }
}


void Game::next_move()
{
    commands.set_numbermove();
    
    switch (number_move)
    {
        case 1:
            player_attack();
            break;
        case 2:
            use_skill();
            break;
        case 3:
            save_game();
            break;
        case 4:
            load_game();
            break;
        default:
            std::cerr << "Unknown number move" << "\n";
            break;
    }
}

void Game::SetNumberMove(int number_move)
{
    this->number_move = number_move;
}

void Game::SetAttackCoord(Coord coord)
{
    attack_coord = coord;
}

void Game::player_attack()
{
    commands.set_playerattackmove();

    try
    {
        shooter(attack_coord);
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
    //print(Table_Player);
    print(Table_Enemy);
    
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
            bot_attack_coords.insert({x, y});
            Table_Player.shoot({x, y});
            was_attack = true;
        }
    }

    print(Table_Player);

}

void Game::use_skill()
{
    try
    {

        auto factory = Manager_Skills.GetFront();

        if (factory->GetName() == SkillName::Scanner)
        {
            commands.set_skillcoord();
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



void Game::SetSkillCoord(Coord coord)
{
    skillcoord = coord;
}


const std::string& Game::GetMessage() const
{
    return message;
}

void Game::SetModeEndGame(int mode)
{
    mode_end = mode;
}