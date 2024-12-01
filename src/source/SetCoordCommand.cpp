#include "../headers/SetCoordCommand.h"

SetCoordCommand::SetCoordCommand() : controller(nullptr) {}

Coord SetCoordCommand::execute() {
    if (controller != nullptr) {
        return controller->setCoord();
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void SetCoordCommand::SetInput(ControllerStartGame* controller) {
    this->controller = controller;
}
