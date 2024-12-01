#include "../headers/SetPlaceShipCommand.h"

SetPlaceShipCommand::SetPlaceShipCommand() : input(nullptr) {}

std::vector<int> SetPlaceShipCommand::execute(int len_ship) {
    if (input != nullptr) {
        return input->setPlaceship(len_ship);
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void SetPlaceShipCommand::SetInput(Input* input) {
    this->input = input;
}
