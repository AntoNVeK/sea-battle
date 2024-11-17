#ifndef SKILLRESULT_SERIALIZER_H
#define SKILLRESULT_SERIALIZER_H
#include "Serializer.h"
#include "../SkillResult.h"

class SkillResultSerializer : public Serializer
{

private:
    const SkillResult& results;
    
public:
    SkillResultSerializer(const SkillResult& results);

    void load() override;

};

#endif