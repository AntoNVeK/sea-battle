#include "../headers/DoubleAttack.h"

DoubleAttack::DoubleAttack(Coord coord, SkillResult& results) : coord(coord), results(results)
{
    if (coord.GetX() < 1 || coord.GetY() < 1)
    {
        throw std::invalid_argument("invalid arguments");
    }
}

void DoubleAttack::use(Table& table)
{
    try
    {
        table.shoot(coord);
        table.shoot(coord);
        results.add_result(200, "DoubleAttack success use on Coord " + std::to_string(coord.GetX()) + " " + std::to_string(coord.GetY()));
    }
    catch(const std::runtime_error &err)
    {
        results.add_result(500, "DoubleAttack uncorrect use on Coord " + std::to_string(coord.GetX()) + " " + std::to_string(coord.GetY()) + " Ship already destroyed");
    }

}
