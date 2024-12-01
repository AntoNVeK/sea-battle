#include "../headers/SetCoordCommand.h"

SetCoordCommand::SetCoordCommand() : input(nullptr) {}

Coord SetCoordCommand::execute() {
    if (input != nullptr) {
        return input->setCoord();
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void SetCoordCommand::SetInput(Input* input) {
    this->input = input;
}
