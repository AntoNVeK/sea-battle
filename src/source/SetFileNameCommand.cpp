#include "../headers/SetFileNameCommand.h"

SetFileNameCommand::SetFileNameCommand() : input(nullptr) {}

std::string SetFileNameCommand::execute() {
    if (input != nullptr) {
        return input->setFilename();
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void SetFileNameCommand::SetInput(Input* input) {
    this->input = input;
}
