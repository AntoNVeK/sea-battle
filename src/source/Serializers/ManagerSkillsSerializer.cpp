#include "../../headers/Serializers/ManagerSkillsSerializer.h"


ManagerSkillsSerializer::ManagerSkillsSerializer(const ManagerSkills& manager) : manager(manager)
{}

void ManagerSkillsSerializer::load()
{
    this->__json = json{
        {"skills", manager.GetQueueName()}
    };
    
}
