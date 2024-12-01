#include "../headers/SetModeCommand.h"

SetModeCommand::SetModeCommand() : controller(nullptr) {}

int SetModeCommand::execute() {
    if (controller != nullptr) {
        return controller->setMode();
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void SetModeCommand::SetInput(ControllerStartGame* controller) {
    this->controller = controller;
}
