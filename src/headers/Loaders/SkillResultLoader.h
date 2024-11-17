#ifndef SKILLRESULT_LOADER_H
#define SKILLRESULT_LOADER_H
#include "Loader.h"
#include "../SkillResult.h"

class SkillResultLoader : public Loader
{

private:
    SkillResult& results;
    
public:
    SkillResultLoader(SkillResult& results);

    void loadFromJson(const json& j) override;

};

#endif