#include "../../headers/IO/Input.h"


Input::Input(){}



std::string Input::input()
{
    std::string input;
    std::cin >> input;
    return input;
}