#ifndef SKILLRESULT_SERIALIZER_H
#define SKILLRESULT_SERIALIZER_H
#include "Serializer.h"
#include "../SkillResult.h"

class SkillResultSerializer : public Serializer
{

private:
    SkillResult& results;
    
public:
    SkillResultSerializer(SkillResult& results);

    void load() override;

};

#endif