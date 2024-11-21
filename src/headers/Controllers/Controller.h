#ifndef CONTROLLER_H
#define CONTROLLER_H

// interface
class Controller
{
public:

    virtual void setMode() = 0;
    virtual void setFilename() = 0;
    virtual void setPlaceship() = 0;
    virtual void setNumberMove() = 0;
    virtual void setPlayerAttack() = 0;
    virtual void setSkillCoord() = 0;
    virtual void setModeEnd() = 0;
    virtual void Endgame() = 0;
    virtual ~Controller() = 0;
    
};




#endif