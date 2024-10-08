#include "../headers/GameException.h"


GameException::GameException(const std::string& msg) : std::runtime_error(msg) {}