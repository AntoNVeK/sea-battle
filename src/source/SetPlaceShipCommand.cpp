#include "../headers/SetPlaceShipCommand.h"

SetPlaceShipCommand::SetPlaceShipCommand() : controller(nullptr) {}

std::vector<int> SetPlaceShipCommand::execute(int len_ship) {
    if (controller == nullptr) {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
    return controller->setPlaceship(len_ship);
}

void SetPlaceShipCommand::SetController(IController* controller) {
    this->controller = controller;
}
