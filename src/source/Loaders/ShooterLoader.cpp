#include "../../headers/Loaders/ShooterLoader.h"


ShooterLoader::ShooterLoader(Shooter& shooter) : shooter(shooter)
{}

void ShooterLoader::loadFromJson(const json& j)
{
    shooter.SetState(j["shooter"]["state"] == true ? DoubleAttackState::ON : DoubleAttackState::OFF);
}
