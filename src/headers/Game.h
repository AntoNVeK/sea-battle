#ifndef GAME_H
#define GAME_H
#include "GameState.h"
#include "Table.h"
#include "ManagerSkills.h"
#include "ManagerShips.h"
#include "Ship.h"
#include "SkillResult.h"
#include "skill_name.h"
#include "GetCoord.h"



class Game
{
public:
	Game();

	~Game();

private:
	GameState _state;

};


#endif