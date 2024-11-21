#include "../headers/SetModeEndCommand.h"

SetModeEndCommand::SetModeEndCommand() : controller(nullptr) {}

void SetModeEndCommand::execute() {
    if (controller != nullptr) {
        controller->setModeEnd();
    } else {
        std::cerr << "Error: Controller not set. Cannot execute command.\n";
    }
}

void SetModeEndCommand::SetController(Controller* controller) {
    this->controller = controller;
}
