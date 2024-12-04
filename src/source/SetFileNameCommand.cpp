#include "../headers/SetFileNameCommand.h"

SetFileNameCommand::SetFileNameCommand() : controller(nullptr) {}

std::string SetFileNameCommand::execute() {
    if (controller == nullptr) {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }

    return controller->setFilename();
}

void SetFileNameCommand::SetController(IController* controller) {
    this->controller = controller;
}
