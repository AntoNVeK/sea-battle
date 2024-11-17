#include "../headers/GameState.h"

using json = nlohmann::json;


GameState::GameState(const Table& Table_Player, const Table& Table_Enemy, const ManagerShips& ShipManager_Player, const ManagerShips& ShipManager_Enemy, const ManagerSkills& Manager_Skills, const SkillResult& results)
	: Table_Player(Table_Player), Table_Enemy(Table_Enemy),
	  ShipManager_Player(ShipManager_Player), ShipManager_Enemy(ShipManager_Enemy),
	  Manager_Skills(Manager_Skills),
	  results(results)
{    }

GameState::GameState(const GameState& other)
	: Table_Player(other.Table_Player),
	  Table_Enemy(other.Table_Enemy),

	  ShipManager_Player(other.ShipManager_Player),
	  ShipManager_Enemy(other.ShipManager_Enemy),

	  Manager_Skills(other.Manager_Skills),
	  results(results)
{    }

GameState::GameState(GameState&& other)
	: Table_Player(other.Table_Player),
	  Table_Enemy(other.Table_Enemy),

	  ShipManager_Player(other.ShipManager_Player),
	  ShipManager_Enemy(other.ShipManager_Enemy),

	  Manager_Skills(other.Manager_Skills),
	  results(results)
{    }

GameState& 
GameState::operator=(const GameState& other)
{
	if (this != &other)
	{
		this->Table_Player = other.Table_Player;
		this->Table_Enemy = other.Table_Enemy;
		this->ShipManager_Player = other.ShipManager_Player;
		this->ShipManager_Enemy = other.ShipManager_Enemy;
		this->Manager_Skills = other.Manager_Skills;
		this->results = other.results;
	}
	return *this;
}

GameState& 
GameState::operator=(GameState&& other) 
{
	if (this != &other)
	{
		this->Table_Player = other.Table_Player;
		this->Table_Enemy = other.Table_Enemy;
		this->ShipManager_Player = other.ShipManager_Player;
		this->ShipManager_Enemy = other.ShipManager_Enemy;
		this->Manager_Skills = other.Manager_Skills;
		this->results = other.results;
	}
	return *this;
}


const Table&  GameState::getTable_Player() const 
{ return this->Table_Player; }

const Table& GameState::getTable_Enemy() const 
{ return this->Table_Enemy; }

const ManagerShips& GameState::getShipManager_Player() const 
{ return this->ShipManager_Player; }

const ManagerShips& GameState::getShipManager_Enemy() const 
{ return this->ShipManager_Enemy; }

const ManagerSkills& GameState::getManager_Skills() const 
{ return this->Manager_Skills; }


void 
GameState::setTable_Player(Table& Table_Player) 
{
	this->Table_Player = Table_Player;
}

void 
GameState::setTable_Enemy(Table& Table_Enemy) 
{
	this->Table_Enemy = Table_Enemy;
}

void 
GameState::setShipManager_Player(ManagerShips& ShipManager_Player) 
{
	this->ShipManager_Player = ShipManager_Player;
}

void 
GameState::setShipManager_Enemy(ManagerShips& ShipManager_Enemy) 
{
	this->ShipManager_Enemy = ShipManager_Enemy;
}

void 
GameState::setManager_Skills(ManagerSkills& Manager_Skills) 
{
	this->Manager_Skills = Manager_Skills;
}





void GameState::saveGame(const std::string &fileName) const
{
    

    std::ofstream fileToWrite("../src/saves/"+fileName + ".json");
    if (!fileToWrite.is_open()) {
        throw FileInteractionError("File open error " + fileName+".json\n");
    }


    fileToWrite << *this;
	

    fileToWrite.close();
}


std::ofstream &operator<<(std::ofstream &out,const GameState &state)
{
    json gameStateJson;

    // Сохранение таблицы игрока
    TableSerializer tablePlayerSerializer(state.getTable_Player());
    tablePlayerSerializer.load();
    gameStateJson["Table_Player"] = tablePlayerSerializer.get();

    // Сохранение таблицы противника
    TableSerializer tableEnemySerializer(state.getTable_Player());
    tableEnemySerializer.load();
    gameStateJson["Table_Enemy"] = tableEnemySerializer.get();

    // Сохранение менеджера кораблей игрока
    ManagerShipsSerializer shipManagerPlayerSerializer(state.getShipManager_Player());
    shipManagerPlayerSerializer.load();
    gameStateJson["ShipManager_Player"] = shipManagerPlayerSerializer.get();

    // Сохранение менеджера кораблей противника
    ManagerShipsSerializer shipManagerEnemySerializer(state.getShipManager_Enemy());
    shipManagerEnemySerializer.load();
    gameStateJson["ShipManager_Enemy"] = shipManagerEnemySerializer.get();

    // Сохранение менеджера навыков
    ManagerSkillsSerializer managerSkillsSerializer(state.getManager_Skills());
    managerSkillsSerializer.load();
    gameStateJson["Manager_Skills"] = managerSkillsSerializer.get();

	// Сохранение результатов способностей
    //SkillResultSerializer skillResultSerializer(state.getResult());
    //skillResultSerializer.load();
    //gameStateJson["results"] = skillResultSerializer.get();


    out << gameStateJson.dump(4); // 4 - количество пробелов для отступа


    return out;
}
