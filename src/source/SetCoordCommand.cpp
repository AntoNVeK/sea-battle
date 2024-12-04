#include "../headers/SetCoordCommand.h"

SetCoordCommand::SetCoordCommand() : controller(nullptr) {}

Coord SetCoordCommand::execute() {
    if (controller == nullptr) {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
    return controller->setCoord();
}

void SetCoordCommand::SetController(IController* controller) {
    this->controller = controller;
}
