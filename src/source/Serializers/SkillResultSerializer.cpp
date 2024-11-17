#include "../../headers/Serializers/SkillResultSerializer.h"


SkillResultSerializer::SkillResultSerializer(const SkillResult& results) : results(results)
{}

void SkillResultSerializer::load()
{
   this->__json = json{
        {"results", results.GetResults()}
   };
}
