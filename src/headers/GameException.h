#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H
#include <exception>
#include <string>

class GameException : public std::exception
{
public:

    explicit GameException(const std::string& msg);

    const char* what() const noexcept override;


protected:
    std::string message;

};



#endif