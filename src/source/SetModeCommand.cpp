#include "../headers/SetModeCommand.h"

SetModeCommand::SetModeCommand() : input(nullptr) {}

int SetModeCommand::execute() {
    if (input != nullptr) {
        return input->setMode();
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void SetModeCommand::SetInput(Input* input) {
    this->input = input;
}
