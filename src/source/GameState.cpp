#include "../headers/GameState.h"

using json = nlohmann::json;


GameState::GameState(Table& Table_Player, Table& Table_Enemy, ManagerShips& ShipManager_Player, ManagerShips& ShipManager_Enemy, ManagerSkills& Manager_Skills, Shooter& shooter)
	: Table_Player(Table_Player), Table_Enemy(Table_Enemy),
	  ShipManager_Player(ShipManager_Player), ShipManager_Enemy(ShipManager_Enemy),
	  Manager_Skills(Manager_Skills),
	  shooter(shooter)
{    }

GameState::GameState(const GameState& other)
	: Table_Player(other.Table_Player),
	  Table_Enemy(other.Table_Enemy),

	  ShipManager_Player(other.ShipManager_Player),
	  ShipManager_Enemy(other.ShipManager_Enemy),

	  Manager_Skills(other.Manager_Skills),
	  shooter(shooter)
{    }

GameState::GameState(GameState&& other)
	: Table_Player(other.Table_Player),
	  Table_Enemy(other.Table_Enemy),

	  ShipManager_Player(other.ShipManager_Player),
	  ShipManager_Enemy(other.ShipManager_Enemy),

	  Manager_Skills(other.Manager_Skills),
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
		this->shooter = other.shooter;
	}
	return *this;
}

void GameState::saveGame(std::string Filename) const
{

    json gameStateJson;

 
    TableSerializer tablePlayerSerializer(Table_Player);
    tablePlayerSerializer.load();
    gameStateJson["Table_Player"] = tablePlayerSerializer.get();


    TableSerializer tableEnemySerializer(Table_Enemy);
    tableEnemySerializer.load();
    gameStateJson["Table_Enemy"] = tableEnemySerializer.get();

  
    ManagerShipsSerializer shipManagerPlayerSerializer(ShipManager_Player);
    shipManagerPlayerSerializer.load();
    gameStateJson["ShipManager_Player"] = shipManagerPlayerSerializer.get();

    
    ManagerShipsSerializer shipManagerEnemySerializer(ShipManager_Enemy);
    shipManagerEnemySerializer.load();
    gameStateJson["ShipManager_Enemy"] = shipManagerEnemySerializer.get();

    
    ManagerSkillsSerializer managerSkillsSerializer(Manager_Skills);
    managerSkillsSerializer.load();
    gameStateJson["Manager_Skills"] = managerSkillsSerializer.get();

	ShooterSerializer shooterSerializer(shooter);
    shooterSerializer.load();
    gameStateJson["shooter"] = shooterSerializer.get();
	


	FileWrapper file_wrapper("../src/saves/" + Filename + ".json");
    file_wrapper.write(gameStateJson);
}






void GameState::loadGame(std::string Filename)
{
	FileWrapper file_wrapper("../src/saves/" + Filename + ".json");
    json gameStateJson;

    file_wrapper.read(gameStateJson);

    ManagerSkillsLoader managerskillsloader(Manager_Skills);
	managerskillsloader.loadFromJson(gameStateJson);

	ShooterLoader shooterloader(shooter);
	shooterloader.loadFromJson(gameStateJson);

	json tablePlayerJson = gameStateJson["Table_Player"];
	json managerPlayerJson = gameStateJson["ShipManager_Player"];

	json JsonPlayer;

	JsonPlayer["Table"] = tablePlayerJson;
	JsonPlayer["ManagerShips"] = managerPlayerJson;

    ManagerShipsTableLoader tablePlayerLoader(ShipManager_Player, Table_Player);
    tablePlayerLoader.loadFromJson(JsonPlayer);

    
    json tableEnemyJson = gameStateJson["Table_Enemy"];
	json managerEnemyJson = gameStateJson["ShipManager_Enemy"];

	json JsonEnemy;

	JsonEnemy["Table"] = tableEnemyJson;
	JsonEnemy["ManagerShips"] = managerEnemyJson;
	
    ManagerShipsTableLoader tableEnemyLoader(ShipManager_Enemy, Table_Enemy);
    tableEnemyLoader.loadFromJson(JsonEnemy);

}


void GameState::writeState()
{
    FileWrapper file_wrapper(filename);
    file_wrapper.write(data);
}

std::istream& operator>>(std::istream& is, GameState& game_state)
{
    json jsn;

    is >> jsn;
    game_state.data = jsn;

    if (jsn.is_null())
    {
        throw std::runtime_error("Failed to read valid JSON data.");
    }

    game_state.writeState();
    return is;
}

std::ofstream &operator<<(std::ofstream &os, const GameState &game_state)
{
    FileWrapper file_wrapper(game_state.filename);
    json jsn;

    file_wrapper.read(jsn);

    os << jsn.dump(4) << std::endl;

    return os;
}