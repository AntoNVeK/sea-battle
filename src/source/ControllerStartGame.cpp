#include "../headers/ControllerStartGame.h"

ControllerStartGame::ControllerStartGame(Game& game) : game(game) {}

int ControllerStartGame::setMode() {
    int mode;
    std::cin >> mode;

    return mode;
}



std::string ControllerStartGame::setFilename()
{
    std::string filename;

    ConsolePrinterMessage printer;

    printer.print("Enter filename: ");
    std::cin >> filename;

    
    return filename;
    
}


std::vector<int> ControllerStartGame::setPlaceship(int len_ship)
{

    std::vector<int> arr;


    int x, y, orientation;

    ConsolePrinterMessage printer;
    printer.print("Enter coord and orientation for ship len " + std::to_string(len_ship) + ": (x, y, orientation(0 : horizontical 1 : vertical))");

    std::cin >> x >> y >> orientation;

    arr.push_back(x);
    arr.push_back(y);
    arr.push_back(orientation);


    return arr;

}


int ControllerStartGame::setNumberMove()
{
    int number_move;
    ConsolePrinterMessage printer;
    printer.print("Enter number move (1 for Simple Attack, 2 for Skill, 3 for save game, 4 for load game): ");

    std::cin >> number_move;

    return number_move;

}


Coord ControllerStartGame::setCoord()
{
    int x, y;
    ConsolePrinterMessage printer;
    printer.print("Enter coord: (x y)");
    
    std::cin >> x >> y;

    return Coord(x, y);
}






void ControllerStartGame::Endgame()
{
    ConsolePrinterMessage printer;
    printer.print("End game");
    exit(0);
}


