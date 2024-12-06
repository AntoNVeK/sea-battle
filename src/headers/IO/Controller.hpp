#include "controller.h"

template <typename Inputer, typename Printer_Table, typename Printer_Message>
void Controller<Inputer, Printer_Table, Printer_Message>::initialize_commands()
{
    commands["attack"] = [&]() { 
        game.player_attack();
        view.solve("attack_message");
        view.solve("tables");
        if (!game.get_result_attack())
            game.swap();
        game.check_win_player();
    };
    commands["state_my_ships"] = [&]() { view.solve("state_my_ships"); };
    commands["state_enemy_ships"] = [&]() { view.solve("state_enemy_ships"); };
    commands["end"] = [&]() { game.EndGame(); };
    commands["tables"] = [&]() { view.solve("tables"); };
    commands["show_enemy_ships"] = [&]() { view.solve("show_enemy_ships"); };
    commands["show_my_ships"] = [&]() { view.solve("show_my_ships"); };
    commands["show_my_table"] = [&]() { view.solve("show_my_table"); };
    commands["show_enemy_table"] = [&]() { view.solve("show_enemy_table"); };
    commands["next_skill"] = [&]() { view.solve("next_skill"); };
    commands["save_game"] = [&]() { game.save_game(); };
    commands["load_game"] = [&]() { game.load_game(); };
    commands["use_skill"] = [&]() { 
        view.solve("use_skill");
        game.use_skill(); 
    };
    commands["help"] = [&]() { view.solve("help"); };
}


template <typename Inputer, typename Printer_Table, typename Printer_Message>
void Controller<Inputer, Printer_Table, Printer_Message>::run()
{
    game.play();
    view.solve("show_my_table");
    


    while (isGameRunning)
    {
        if (game.get_current_player() == Player::User)
        {
            view.print_message("Enter command: ");
            std::string input = inputer.getInput();
            if(commands.find(input) != commands.end())
            {
                commands[input]();
            }
        }
        else
        {
            game.computer_attack();
            view.solve("attack_message");
            view.solve("tables");
            if (!game.get_result_attack())
                game.swap();
            game.check_win_bot();
        }
        
    }
    
}





template <typename Inputer, typename Printer_Table, typename Printer_Message>
int Controller<Inputer, Printer_Table, Printer_Message>::setMode() {
    int mode;
    bool valid = false;

    while (!valid)
    {
        std::string inputStr = inputer.getString();
        std::stringstream ss(inputStr);

        ss >> mode;
        if ((inputStr != ""))
        {
            
            if ((inputStr != "") && (ss.fail() || ss.bad() || mode < 1 || mode > 2))
            {
                view.print_message("Invalid input. Please enter one number (mode): \n");
                continue;
            }

            valid = true;
        }

    }



    return mode;
}


template <typename Inputer, typename Printer_Table, typename Printer_Message>
std::string Controller<Inputer, Printer_Table, Printer_Message>::setFilename()
{

    view.print_message("Enter filename: ");
    std::string filename = inputer.getString();

    
    return filename;
    
}



template <typename Inputer, typename Printer_Table, typename Printer_Message>
std::vector<int> Controller<Inputer, Printer_Table, Printer_Message>::setPlaceship(int len_ship)
{

    std::vector<int> arr;

    view.solve("show_my_table");

    int x, y, orientation;


    view.print_message("Enter coord and orientation for ship len " + std::to_string(len_ship) + ": (x, y, orientation(0 : horizontical 1 : vertical))\n");

    bool valid = false;

    while (!valid)
    {
        std::string inputStr = inputer.getString();
        std::stringstream ss(inputStr);

        ss >> x >> y >> orientation;
        if ((inputStr != ""))
        {
            
            if ((inputStr != "") && (ss.fail() || ss.bad() || x < 0 || y < 0 || orientation < 0 || orientation > 1))
            {
                view.print_message("Invalid input. Please enter three numbers (x, y, orientation): \n");
                continue;
            }

            valid = true;
        }

    }


    arr.push_back(x);
    arr.push_back(y);
    arr.push_back(orientation);




    return arr;

}



template <typename Inputer, typename Printer_Table, typename Printer_Message>
Coord Controller<Inputer, Printer_Table, Printer_Message>::setCoord()
{
    int x, y;

    view.print_message("Enter coord: (x y)\n");
    
    bool valid = false;

    while (!valid)
    {
        std::string inputStr = inputer.getString();
        std::stringstream ss(inputStr);

        ss >> x >> y;
        if ((inputStr != ""))
        {
            
            if ((inputStr != "") && (ss.fail() || ss.bad() || x < 0 || y < 0))
            {
                view.print_message("Invalid input. Please enter two numbers (x, y): \n");
                continue;
            }

            valid = true;
        }

    }

    return Coord(x, y);
}





template <typename Inputer, typename Printer_Table, typename Printer_Message>
void Controller<Inputer, Printer_Table, Printer_Message>::Endgame()
{

    view.print_message("End game\n");
    isGameRunning = false;
}

template <typename Inputer, typename Printer_Table, typename Printer_Message>
void Controller<Inputer, Printer_Table, Printer_Message>::print_message(std::string string)
{
    view.print_message(string);
}
