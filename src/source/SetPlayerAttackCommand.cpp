#include "../headers/SetPlayerAttackCommand.h"

SetPlayerAttackCommand::SetPlayerAttackCommand() : controller(nullptr) {}

void SetPlayerAttackCommand::execute() {
    if (controller != nullptr) {
        controller->setPlayerAttack();
    } else {
        std::cerr << "Error: Controller not set. Cannot execute command.\n";
    }
}

void SetPlayerAttackCommand::SetController(Controller* controller) {
    this->controller = controller;
}
