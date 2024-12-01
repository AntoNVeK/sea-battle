#include "../headers/SetPlaceShipCommand.h"

SetPlaceShipCommand::SetPlaceShipCommand() : controller(nullptr) {}

std::vector<int> SetPlaceShipCommand::execute(int len_ship) {
    if (controller != nullptr) {
        return controller->setPlaceship(len_ship);
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void SetPlaceShipCommand::SetInput(ControllerStartGame* controller) {
    this->controller = controller;
}
