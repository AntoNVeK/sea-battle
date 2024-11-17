#ifndef OOP_FILEINTERACTIONERROR_H
#define OOP_FILEINTERACTIONERROR_H
#include <iostream>
#include "GameException.h"

class FileInteractionError : public GameException {
public:
    FileInteractionError(const std::string& msg);
};


#endif