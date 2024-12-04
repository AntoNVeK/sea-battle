#include "../headers/EndGameCommand.h"

EndGameCommand::EndGameCommand() : controller(nullptr) {}

void EndGameCommand::execute() {
    if (controller != nullptr) {
        controller->Endgame();
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void EndGameCommand::SetController(IController* controller) {
    this->controller = controller;
}
