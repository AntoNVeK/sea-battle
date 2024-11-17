#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <fstream>
#include <sstream>
#include <filesystem>
#include "FileInteractionError.h"
#include "Table.h"
#include "ManagerShips.h"
#include "ManagerSkills.h"
#include "Serializers/CoordSerializer.h"
#include "Serializers/ManagerShipsSerializer.h"
#include "Serializers/ManagerSkillsSerializer.h"
#include "Serializers/Serializer.h"
#include "Serializers/ShipSerializer.h"
#include "Serializers/ShooterSerializer.h"
#include "Serializers/SkillResultSerializer.h"
#include "Serializers/TableSerializer.h"

class GameState
{

public:
	GameState(Table& Table_Player, Table& Table_Enemy, ManagerShips& ShipManager_Player, ManagerShips& ShipManager_Enemy, ManagerSkills& Manager_Skills);

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

	void saveGame(const std::string& fileName);
    void loadGame(const std::string& filename);

	

private:
	Table Table_Player;
	Table Table_Enemy;

	ManagerShips ShipManager_Player;
	ManagerShips ShipManager_Enemy;

	ManagerSkills Manager_Skills;

public:
	std::string filename;

};


#endif