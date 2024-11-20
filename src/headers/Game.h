#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "GameState.h"
#include "Table.h"
#include "ManagerSkills.h"
#include "ManagerShips.h"
#include "Ship.h"
#include "SkillResult.h"
#include "skill_name.h"
#include "GetCoord.h"
#include "GameEnums.h"
#include "SetModeCommand.h"

class Game
{
public:
	Game(Command* set_mode_command);

	void play();

	void SetModeStartGame(ModeStartGame mode);

private:
	GameState state;
	
	
	Table Table_Player;
	Table Table_Enemy;

	ManagerShips ShipManager_Player;
	ManagerShips ShipManager_Enemy;

	SkillResult results;

	Shooter shooter;

	Coord skillcoord;

	GetCoord command;

	SkillFactory skillfactory;

	ManagerSkills Manager_Skills;


	Coord attack_coord;


	ModeStartGame mode;

	Command* set_mode_command;
	

};


#endif