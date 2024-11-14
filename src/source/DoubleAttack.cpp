#include "../headers/DoubleAttack.h"

DoubleAttack::DoubleAttack(SkillResult& results, Shooter& shooter) : results(results), shooter(shooter)
{

}

void DoubleAttack::use()
{
    shooter.SetState(DoubleAttackState::ON);
    results.add_result("next shoot will double");
}
