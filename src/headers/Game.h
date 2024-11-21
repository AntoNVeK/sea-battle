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
#include "Commands.h"

class Game
{
public:
	Game(Commands& commands);

	void load_game();

	void save_game();

	void play();

	void SetModeStartGame(ModeStartGame mode);

	void SetFilename(std::string filename);

	void start_new_game();

	void SetPlaceShip(Coord coord, Orientation orientation);

	void SetNumberMove(int number_move);

	void SetAttackCoord(Coord coord);

	const Ship& GetShipNeedPlacement() const;

	void placeEnemyShips();

	void print(Table& table);

	void check_end_game();

	void next_move();

	void player_attack();

	void computer_attack();

	void use_skill();

	void SetSkillCoord(Coord coord);

	const std::string& GetMessage() const;

	void SetModeEndGame(int mode);
	
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

	ModeStartGame mode;

	Commands commands;
	
	std::string filename;

	Ship& ship;

	Coord coord_place_ship;

	Orientation orientation_place_ship;

	int number_move;
	
	Coord attack_coord;

	std::set<Coord> bot_attack_coords;
	
	std::string message;

	int mode_end;

};


#endif