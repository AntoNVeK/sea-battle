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
#include "Loaders/Loader.h"
#include "Loaders/ManagerSkillsLoader.h"
#include "Loaders/ShooterLoader.h"
#include "Loaders/SkillResultLoader.h"
#include "Loaders/ManagerShipsTableLoader.h"

class GameState
{

public:
	GameState(Table& Table_Player, Table& Table_Enemy, ManagerShips& ShipManager_Player, ManagerShips& ShipManager_Enemy, ManagerSkills& Manager_Skills, SkillResult& results, Shooter& shooter);

	GameState(const GameState& other);
	GameState(GameState&& other);

	~GameState() = default;

	GameState& operator=(const GameState& other);
	GameState& operator=(GameState&& other);

	Table& getTable_Player() const;
	Table& getTable_Enemy() const;

	ManagerShips& getShipManager_Player() const;
	ManagerShips& getShipManager_Enemy() const;

	ManagerSkills& getManager_Skills() const;

	SkillResult& getResult() const;

	Shooter& getShooter() const;

	void setTable_Player(Table& Table_Player);
	void setTable_Enemy(Table& Table_Enemy);

	void setShipManager_Player(ManagerShips& ShipManager_Player);
	void setShipManager_Enemy(ManagerShips& ShipManager_Enemy);

	void setManager_Skills(ManagerSkills& Manager_Skills);

	void setResult(SkillResult& results);

	void setShooter(Shooter& shooter);

	void saveGame(const std::string& fileName) const;
    void loadGame(const std::string& filename);

	

private:
	Table& Table_Player;
	Table& Table_Enemy;

	ManagerShips& ShipManager_Player;
	ManagerShips& ShipManager_Enemy;

	ManagerSkills& Manager_Skills;

	SkillResult& results;

	Shooter& shooter;


};


std::ofstream &operator<<(std::ofstream &out,const GameState &state);
std::istream &operator>>(std::istream &in, GameState &state);


#endif