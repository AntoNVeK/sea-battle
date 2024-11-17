#include "../../headers/Serializers/ShooterSerializer.h"


ShooterSerializer::ShooterSerializer(const Shooter& shooter) : shooter(shooter)
{}

void ShooterSerializer::load()
{
   this->__json = json{
        {"state", shooter.DoubleAttack()}
   };
}
