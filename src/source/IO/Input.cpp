#include "../../headers/IO/Input.h"


Input::Input(){}



std::string Input::input()
{
    std::string controller;
    std::getline(std::cin, controller);
    return controller;
}