#include "../headers/EndGameCommand.h"

EndGameCommand::EndGameCommand() : input(nullptr) {}

void EndGameCommand::execute() {
    if (input != nullptr) {
        input->Endgame();
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void EndGameCommand::SetInput(Input* input) {
    this->input = input;
}
