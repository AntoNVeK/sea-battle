#ifndef SKILL_RESULT_H
#define SKILL_RESULT_H
#include <map>
#include <string>
#include <vector>

class SkillResult
{
private:
    std::vector<std::string> results;

public:
    const std::vector<std::string>& GetResults() const;
    
    const std::string& GetLast() const;
    
    void add_result(const std::string& data);
    
    bool empty() const;

    void pop();
};

#endif