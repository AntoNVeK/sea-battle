#include "controller.h"

template <typename Inputer, typename Printer_Table, typename Printer_Message>
void Controller<Inputer, Printer_Table, Printer_Message>::initialize_commands()
{
    commands["attack"] = [&]() { 
        game.player_attack();
        view.solve("fields");
    };
    commands["state_my_ships"] = [&]() { view.solve("state_my_ships"); };
    commands["state_enemy_ships"] = [&]() { view.solve("state_enemy_ships"); };
    commands["end"] = [&]() { game.EndGame(); };
    commands["fields"] = [&]() { view.solve("fields"); };
    commands["show_enemy_ships"] = [&]() { view.solve("show_enemy_ships"); };
    commands["show_my_ships"] = [&]() { view.solve("show_my_ships"); };
    commands["next_ability"] = [&]() { view.solve("next_ability"); };
    commands["save_game"] = [&]() { game.save_game(); };
    commands["load_game"] = [&]() { game.load_game(); };
    commands["apply_ability"] = [&]() { 
        game.use_skill(); 
        view.solve("apply_ability");
    };
    commands["help"] = [&]() { view.solve("help"); };
}


template <typename Inputer, typename Printer_Table, typename Printer_Message>
void Controller<Inputer, Printer_Table, Printer_Message>::run()
{
    game.play();
    bool isGameRunning = true;


    while (isGameRunning)
    {
        std::string input = inputer.getInput();
        if(commands.find(input) != commands.end())
        {
            commands[input]();
        }
        else
        {
            std::cout << "Unknown command" << std::endl;
        }
        
        game.computer_attack();
        game.check_end_game();
        view.solve("attack_message");
        view.solve("fields");
    }
    
}