#include "../headers/SkillResult.h"

const std::vector<std::string>& SkillResult::GetResults() const
{
    return this->results;
}

const std::string& SkillResult::GetLast() const
{
    return results.back();
}

void SkillResult::add_result(const std::string& data)
{
    results.push_back(data);
}

bool SkillResult::empty() const
{
    return results.empty();
}


void SkillResult::pop()
{
    results.pop_back();
}