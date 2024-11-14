#include "../headers/GameState.h"

GameState::GameState(const Table& Table_Player, const Table& Table_Enemy, const ManagerShips& ShipManager_Player, const ManagerShips& ShipManager_Enemy, const ManagerSkills& Manager_Skills)
	: Table_Player(Table_Player), Table_Enemy(Table_Enemy),
	  ShipManager_Player(ShipManager_Player), ShipManager_Enemy(ShipManager_Enemy),
	  Manager_Skills(Manager_Skills)
{    }

GameState::GameState(const GameState& other)
	: Table_Player(other.Table_Player),
	  Table_Enemy(other.Table_Enemy),

	  ShipManager_Player(other.ShipManager_Player),
	  ShipManager_Enemy(other.ShipManager_Enemy),

	  Manager_Skills(other.Manager_Skills)
{    }

GameState::GameState(GameState&& other)
	: Table_Player(other.Table_Player),
	  Table_Enemy(other.Table_Enemy),

	  ShipManager_Player(other.ShipManager_Player),
	  ShipManager_Enemy(other.ShipManager_Enemy),

	  Manager_Skills(other.Manager_Skills)
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
	}
	return *this;
}


const Table& 
GameState::getTable_Player() const 
{ return this->Table_Player; }

const Table& 
GameState::getTable_Enemy() const 
{ return this->Table_Enemy; }

const ManagerShips&
GameState::getShipManager_Player() const 
{ return this->ShipManager_Player; }

const ManagerShips&
GameState::getShipManager_Enemy() const 
{ return this->ShipManager_Enemy; }

const ManagerSkills&
GameState::getManager_Skills() const 
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