#ifndef MANAGERSKILLS_H
#define MANAGERSKILLS_H
#include "ISkill.h"
#include <queue>
#include <memory>
#include "DoubleAttack.h"
#include "Scanner.h"
#include "Attack.h"

class ISkill;

class ManagerSkills
{
private:
    std::queue<std::shared_ptr<ISkill>> skills;
public:

    ManagerSkills();

    void use_skill(Table& table, const Coord& coord);

    void use_skill(Table& table, int x, int y);





    ManagerSkills(const ManagerSkills &other);
    ManagerSkills(ManagerSkills &&other);


    ManagerSkills& operator=(const ManagerSkills &other);
    ManagerSkills& operator=(ManagerSkills &&other);


    void add_skill();
};



#endif