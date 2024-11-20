#include "../headers/SetModeCommand.h"

SetModeCommand::SetModeCommand() : controller(nullptr) {}

void SetModeCommand::execute() {
    if (controller != nullptr) {
        controller->setMode();
    } else {
        std::cerr << "Error: Controller not set. Cannot execute command.\n";
    }
}

void SetModeCommand::SetController(Controller* controller) {
    this->controller = controller;
}
