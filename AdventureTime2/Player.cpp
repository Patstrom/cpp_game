#include "stdafx.h"
#include "Player.h"


AdventureTime::Player::Player() :
currentRoom(1)
{
}

AdventureTime::Player::~Player()
{

}

void AdventureTime::Player::setPlayerName(const std::string s)
{
	playerName = s;
}

int AdventureTime::Player::getCurrentRoom()
{
	return currentRoom;
}

void AdventureTime::Player::setCurrentRoom(int e)
{
	currentRoom = e;
}

void AdventureTime::Player::addItem(Item item)
{

}

void AdventureTime::Player::removeItem(Item item)
{

}
