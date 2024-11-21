#include "../headers/SetSkillCoordCommand.h"

SetSkillCoordCommand::SetSkillCoordCommand() : controller(nullptr) {}

void SetSkillCoordCommand::execute() {
    if (controller != nullptr) {
        controller->setSkillCoord();
    } else {
        std::cerr << "Error: Controller not set. Cannot execute command.\n";
    }
}

void SetSkillCoordCommand::SetController(Controller* controller) {
    this->controller = controller;
}
