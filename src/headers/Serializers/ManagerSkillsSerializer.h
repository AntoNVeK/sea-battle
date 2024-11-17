#ifndef MANAGER_SKILLS_SERIALIZER_H
#define MANAGER_SKILLS_SERIALIZER_H
#include "Serializer.h"
#include "../ManagerSkills.h"

class ManagerSkillsSerializer : public Serializer
{

private:
    const ManagerSkills& manager;
    
public:
    ManagerSkillsSerializer(const ManagerSkills& manager);

    void load() override;

};

#endif