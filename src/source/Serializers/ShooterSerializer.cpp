#include "../../headers/Serializers/ShooterSerializer.h"


ShooterSerializer::ShooterSerializer(Shooter& shooter) : shooter(shooter)
{}

void ShooterSerializer::load()
{
   this->__json = json{
        {"state", shooter.DoubleAttack()}
   };
}
