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
#include "FileWrapper.h"

class GameState
{

public:
	GameState(Table& Table_Player, Table& Table_Enemy, ManagerShips& ShipManager_Player, ManagerShips& ShipManager_Enemy, ManagerSkills& Manager_Skills, Shooter& shooter);

	GameState(const GameState& other);
	GameState(GameState&& other);

	~GameState() = default;

	GameState& operator=(const GameState& other);
	GameState& operator=(GameState&& other);

	void saveGame(std::string Filename) const;
    void loadGame(std::string Filename);


	void writeState();

	friend std::ofstream &operator<<(std::ofstream &out,const GameState &state);
	friend std::istream &operator>>(std::istream &in, GameState &state);

private:
	Table& Table_Player;
	Table& Table_Enemy;

	ManagerShips& ShipManager_Player;
	ManagerShips& ShipManager_Enemy;

	ManagerSkills& Manager_Skills;

	Shooter& shooter;

	json data;
	
	
	std::string filename;

};





#endif