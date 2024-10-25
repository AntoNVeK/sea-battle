#ifndef ATTACK_H
#define ATTACK_H
#include "ISkill.h"
#include "Table.h"
#include <ctime>


class Attack : public ISkill
{
public:
    Attack();

    void use(Table& table) override;   
    
    ~Attack() override = default;
private:
    Ship& get_random_ship_for_attack(const Table& table);

    int get_random_index_segment_ship(const Ship& ship);

};



#endif