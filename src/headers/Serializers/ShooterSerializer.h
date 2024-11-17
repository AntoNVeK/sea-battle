#ifndef SHOTTER_SERIALIZER_H
#define SHOTTER_SERIALIZER_H
#include "Serializer.h"
#include "../Shooter.h"

class ShooterSerializer : public Serializer
{

private:
    const Shooter& shooter;
    
public:
    ShooterSerializer(const Shooter& shooter);

    void load() override;

};

#endif