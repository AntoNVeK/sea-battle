#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Table.h"
#include "ManagerShips.h"
#include "ManagerSkills.h"

class GameState
{

public:
	GameState(const Table& Table_Player, const Table& Table_Enemy, const ManagerShips& ShipManager_Player, const ManagerShips& ShipManager_Enemy, const ManagerSkills& Manager_Skills);

	GameState(const GameState& other);
	GameState(GameState&& other);

	~GameState() = default;

	GameState& operator=(const GameState& other);
	GameState& operator=(GameState&& other);

	const Table& getTable_Player() const;
	const Table& getTable_Enemy() const;

	const ManagerShips& getShipManager_Player() const;
	const ManagerShips& getShipManager_Enemy() const;

	const ManagerSkills& getManager_Skills() const;


	void setTable_Player(Table& Table_Player);
	void setTable_Enemy(Table& Table_Enemy);

	void setShipManager_Player(ManagerShips& ShipManager_Player);
	void setShipManager_Enemy(ManagerShips& ShipManager_Enemy);

	void setManager_Skills(ManagerSkills& Manager_Skills);

	void download();

	

private:
	Table Table_Player;
	Table Table_Enemy;

	ManagerShips ShipManager_Player;
	ManagerShips ShipManager_Enemy;

	ManagerSkills Manager_Skills;

};


#endif