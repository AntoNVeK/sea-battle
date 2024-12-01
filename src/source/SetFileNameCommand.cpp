#include "../headers/SetFileNameCommand.h"

SetFileNameCommand::SetFileNameCommand() : controller(nullptr) {}

std::string SetFileNameCommand::execute() {
    if (controller != nullptr) {
        return controller->setFilename();
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void SetFileNameCommand::SetInput(ControllerStartGame* controller) {
    this->controller = controller;
}
