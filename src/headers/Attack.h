#ifndef ATTACK_H
#define ATTACK_H
#include "ISkill.h"
#include "ManagerShips.h"
#include <ctime>


class Attack : public ISkill
{
private:
    ManagerShips& manager;

public:
    Attack(ManagerShips& manager);

    void use() override;   
    
    ~Attack() override = default;
private:
    int get_random_index_ship_for_attack(const ManagerShips& manager);

    int get_random_index_segment_ship(const Ship& ship);

};



#endif