#include "../headers/EndGameCommand.h"

EndGameCommand::EndGameCommand() : controller(nullptr) {}

void EndGameCommand::execute() {
    if (controller != nullptr) {
        controller->Endgame();
    } else {
        std::cerr << "Error: Controller not set. Cannot execute command.\n";
    }
}

void EndGameCommand::SetController(Controller* controller) {
    this->controller = controller;
}
