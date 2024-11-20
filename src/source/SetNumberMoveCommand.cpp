#include "../headers/SetNumberMoveCommand.h"

SetNumberMoveCommand::SetNumberMoveCommand() : controller(nullptr) {}

void SetNumberMoveCommand::execute() {
    if (controller != nullptr) {
        controller->setNumberMove();
    } else {
        std::cerr << "Error: Controller not set. Cannot execute command.\n";
    }
}

void SetNumberMoveCommand::SetController(Controller* controller) {
    this->controller = controller;
}
