#include "../headers/PrintMessageCommand.h"

PrintMessageCommand::PrintMessageCommand() : controller(nullptr) {}

void PrintMessageCommand::execute(std::string string) {
    if (controller != nullptr) {
        controller->print_message(string);
    } else {
        std::cerr << "Error: Input not set. Cannot execute command.\n";
    }
}

void PrintMessageCommand::SetController(IController* controller) {
    this->controller = controller;
}
