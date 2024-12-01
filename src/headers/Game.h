#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
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
#include "SetModeCommand.h"
#include "SetFileNameCommand.h"
#include "SetPlaceShipCommand.h"
#include "SetCoordCommand.h"
#include "EndGameCommand.h"

class Game
{
public:
	Game(SetFileNameCommand& set_file_name, SetModeCommand& set_mode, SetCoordCommand& set_coord, SetPlaceShipCommand& set_place_ship, EndGameCommand& end_game);

	void load_game();

	void save_game();

	void play();

	void start_new_game();

	void placePlayerShips();

	void placeEnemyShips();

	void print(Table& table, bool flag);

	void check_end_game();

	void player_attack();

	void computer_attack();

	void use_skill();

	Table& get_player_table();

	Table& get_enemy_table();

	ManagerShips& get_player_ships();
	
	ManagerShips& get_enemy_ships();


	bool get_result_attack() const
	{
		return last_attack_result;
	}

	SkillName get_name_next_skill() const
	{
		return Manager_Skills.GetNameFrontSkill();
	}
	
	void swap();
	
	Player get_current_player() const
	{
		return current_player;
	}

	void EndGame();
	
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

	std::set<Coord> bot_attack_coords;

	SetFileNameCommand& set_file_name;
	SetModeCommand& set_mode;
	SetCoordCommand& set_coord;
	SetPlaceShipCommand& set_place_ship;
	EndGameCommand& end_game;


	bool last_attack_result = false;

	Player current_player = Player::User;

};


#endif