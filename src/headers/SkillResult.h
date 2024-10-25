#ifndef SKILL_RESULT_H
#define SKILL_RESULT_H
#include <map>
#include <string>
#include <vector>

class SkillResult
{
private:
    std::vector<std::map<std::string, std::string>> results;

public:
    const std::vector<std::map<std::string, std::string>>& GetResults() const;
    
    const std::string& GetLast() const;
    
    void add_result(int status, const std::string& data);
    
    bool empty() const;
};

#endif