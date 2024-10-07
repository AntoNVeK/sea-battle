#ifndef MANAGERSKILLS_H
#define MANAGERSKILLS_H
#include "ISkill.h"
#include <queue>
#include <memory>
#include <random>
#include <algorithm>
#include "DoubleAttack.h"
#include "Scanner.h"
#include "Attack.h"
#include <typeinfo>
#include "Observer.h"



class ISkill;

class ManagerSkills : public Observer
{
private:
    std::queue<std::shared_ptr<ISkill>> skills;
public:

    ManagerSkills();

    void use_skill(Table& table, const Coord& coord);

    void use_skill(Table& table, int x, int y);

    void accept() override;

    ManagerSkills(const ManagerSkills &other);
    ManagerSkills(ManagerSkills &&other);


    ManagerSkills& operator=(const ManagerSkills &other);
    ManagerSkills& operator=(ManagerSkills &&other);


    void add_skill();
};



#endif