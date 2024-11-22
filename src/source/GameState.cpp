#include "../headers/GameState.h"

using json = nlohmann::json;


GameState::GameState(Table& Table_Player, Table& Table_Enemy, ManagerShips& ShipManager_Player, ManagerShips& ShipManager_Enemy, ManagerSkills& Manager_Skills, SkillResult& results, Shooter& shooter)
	: Table_Player(Table_Player), Table_Enemy(Table_Enemy),
	  ShipManager_Player(ShipManager_Player), ShipManager_Enemy(ShipManager_Enemy),
	  Manager_Skills(Manager_Skills),
	  results(results),
	  shooter(shooter)
{    }

GameState::GameState(const GameState& other)
	: Table_Player(other.Table_Player),
	  Table_Enemy(other.Table_Enemy),

	  ShipManager_Player(other.ShipManager_Player),
	  ShipManager_Enemy(other.ShipManager_Enemy),

	  Manager_Skills(other.Manager_Skills),
	  results(results),
	  shooter(shooter)
{    }

GameState::GameState(GameState&& other)
	: Table_Player(other.Table_Player),
	  Table_Enemy(other.Table_Enemy),

	  ShipManager_Player(other.ShipManager_Player),
	  ShipManager_Enemy(other.ShipManager_Enemy),

	  Manager_Skills(other.Manager_Skills),
	  results(results),
	  shooter(shooter)
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
		this->shooter = other.shooter;
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
		this->shooter = other.shooter;
	}
	return *this;
}


Table&  GameState::getTable_Player() const 
{ return this->Table_Player; }

Table& GameState::getTable_Enemy() const 
{ return this->Table_Enemy; }

ManagerShips& GameState::getShipManager_Player() const 
{ return this->ShipManager_Player; }

ManagerShips& GameState::getShipManager_Enemy() const 
{ return this->ShipManager_Enemy; }

ManagerSkills& GameState::getManager_Skills() const 
{ return this->Manager_Skills; }

SkillResult& GameState::getResult() const
{ return this->results;}

Shooter& GameState::getShooter() const
{ return this->shooter;}

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

void GameState::setResult(SkillResult& results)
{
	this->results = results;
}

void GameState::setShooter(Shooter& shooter)
{
	this->shooter = shooter;
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

 
    TableSerializer tablePlayerSerializer(state.getTable_Player());
    tablePlayerSerializer.load();
    gameStateJson["Table_Player"] = tablePlayerSerializer.get();


    TableSerializer tableEnemySerializer(state.getTable_Enemy());
    tableEnemySerializer.load();
    gameStateJson["Table_Enemy"] = tableEnemySerializer.get();

  
    ManagerShipsSerializer shipManagerPlayerSerializer(state.getShipManager_Player());
    shipManagerPlayerSerializer.load();
    gameStateJson["ShipManager_Player"] = shipManagerPlayerSerializer.get();

    
    ManagerShipsSerializer shipManagerEnemySerializer(state.getShipManager_Enemy());
    shipManagerEnemySerializer.load();
    gameStateJson["ShipManager_Enemy"] = shipManagerEnemySerializer.get();

    
    ManagerSkillsSerializer managerSkillsSerializer(state.getManager_Skills());
    managerSkillsSerializer.load();
    gameStateJson["Manager_Skills"] = managerSkillsSerializer.get();

	
    SkillResultSerializer skillResultSerializer(state.getResult());
    skillResultSerializer.load();
    gameStateJson["results"] = skillResultSerializer.get();

	ShooterSerializer shooterSerializer(state.getShooter());
    shooterSerializer.load();
    gameStateJson["shooter"] = shooterSerializer.get();


    out << gameStateJson.dump(4);


    return out;
}



void GameState::loadGame(const std::string& filename)
{
	

    std::ifstream fileToRead("../src/saves/" + filename + ".json");
    if (!fileToRead.is_open()) {
        throw FileInteractionError("File open error " + filename+".json\n");
    }

    fileToRead >> *this;

    fileToRead.close();
}


std::istream &operator>>(std::istream &in, GameState &state)
{
	json gameStateJson;
	in >> gameStateJson;
	
	ManagerSkillsLoader managerskillsloader(state.getManager_Skills());
	managerskillsloader.loadFromJson(gameStateJson);

	ShooterLoader shooterloader(state.getShooter());
	shooterloader.loadFromJson(gameStateJson);

	SkillResultLoader skillresultloader(state.getResult());
	skillresultloader.loadFromJson(gameStateJson);



	json tablePlayerJson = gameStateJson["Table_Player"];
	json managerPlayerJson = gameStateJson["ShipManager_Player"];

	json JsonPlayer;

	JsonPlayer["Table"] = tablePlayerJson;
	JsonPlayer["ManagerShips"] = managerPlayerJson;

    ManagerShipsTableLoader tablePlayerLoader(state.getShipManager_Player(), state.getTable_Player());
    tablePlayerLoader.loadFromJson(JsonPlayer);

    
    json tableEnemyJson = gameStateJson["Table_Enemy"];
	json managerEnemyJson = gameStateJson["ShipManager_Enemy"];

	json JsonEnemy;

	JsonEnemy["Table"] = tableEnemyJson;
	JsonEnemy["ManagerShips"] = managerEnemyJson;
	
    ManagerShipsTableLoader tableEnemyLoader(state.getShipManager_Enemy(), state.getTable_Enemy());
    tableEnemyLoader.loadFromJson(JsonEnemy);

	
	return in;
}