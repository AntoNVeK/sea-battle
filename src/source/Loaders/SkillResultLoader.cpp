#include "../../headers/Loaders/SkillResultLoader.h"


SkillResultLoader::SkillResultLoader(SkillResult& results) : results(results)
{}

void SkillResultLoader::loadFromJson(const json& j)
{
    SkillResult res;
    for (const auto& result : j["results"]["results"]) {
        res.add_result(result);
    }
    results = res;
}
