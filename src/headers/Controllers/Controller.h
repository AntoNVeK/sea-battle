#ifndef CONTROLLER_H
#define CONTROLLER_H

// interface
class Controller
{
public:

    virtual void setMode() = 0;
    virtual void setFilename() = 0;
    virtual ~Controller() = 0;
    
};




#endif