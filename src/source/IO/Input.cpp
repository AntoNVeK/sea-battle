#include "../../headers/IO/Input.h"


Input::Input(){}



std::string Input::input()
{
    std::string input;
    getline(std::cin, input);
    return input;
}