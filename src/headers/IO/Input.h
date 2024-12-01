#ifndef INPUT_H
#define INPUT_H
#include <string>
#include "../Coord.h"
#include <vector>

// interface
class Input // CliInput
{
public:

    virtual int setMode() = 0;
    virtual std::string setFilename() = 0;
    virtual std::vector<int> setPlaceship(int len_ship) = 0;
    virtual int setNumberMove() = 0;
    virtual Coord setCoord() = 0;
    virtual void Endgame() = 0;
    virtual std::string input() = 0;
    virtual ~Input() = 0;
    
};




#endif