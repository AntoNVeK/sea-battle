#ifndef SHOOTER_LOADER_H
#define SHOOTER_LOADER_H
#include "Loader.h"
#include "../Shooter.h"

class ShooterLoader : public Loader
{

private:
    Shooter& shooter;
    
public:
    ShooterLoader(Shooter& shooter);

    void loadFromJson(const json& j) override;

};

#endif