#include "../headers/SetFileNameCommand.h"

SetFileNameCommand::SetFileNameCommand() : controller(nullptr) {}

void SetFileNameCommand::execute() {
    if (controller != nullptr) {
        controller->setFilename();
    } else {
        std::cerr << "Error: Controller not set. Cannot execute command.\n";
    }
}

void SetFileNameCommand::SetController(Controller* controller) {
    this->controller = controller;
}
