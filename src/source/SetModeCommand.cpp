#include "../headers/SetModeCommand.h"

SetModeCommand::SetModeCommand() : controller(nullptr) {}

int SetModeCommand::execute() {
    if (controller == nullptr) {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
    return controller->setMode();
}

void SetModeCommand::SetController(IController* controller) {
    this->controller = controller;
}
