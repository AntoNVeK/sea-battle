#include "../headers/SkillResult.h"

const std::vector<std::map<std::string, std::string>>& SkillResult::GetResults() const
{
    return this->results;
}

const std::string& SkillResult::GetLast() const
{
    return results.back().at("data");
}

void SkillResult::add_result(int status, const std::string& data)
{
    std::map<std::string, std::string> result;
    result["status"] = std::to_string(status);
    result["data"] = data;
    results.push_back(result);
}

bool SkillResult::empty() const
{
    return results.empty();
}