#include "../headers/SetPlaceShipCommand.h"

SetPlaceShipCommand::SetPlaceShipCommand() : controller(nullptr) {}

void SetPlaceShipCommand::execute() {
    if (controller != nullptr) {
        controller->setPlaceship();
    } else {
        std::cerr << "Error: Controller not set. Cannot execute command.\n";
    }
}

void SetPlaceShipCommand::SetController(Controller* controller) {
    this->controller = controller;
}
