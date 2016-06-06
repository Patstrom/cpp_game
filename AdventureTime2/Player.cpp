#include "stdafx.h"
#include "Player.h"


AdventureTime::Player::Player() :
currentRoom(1)
{
}


void AdventureTime::Player::setPlayerName(const std::string s)
{
	playerName = s;
}

int AdventureTime::Player::getCurrentRoom() const
{
	return currentRoom;
}

void AdventureTime::Player::setCurrentRoom(int e)
{
	currentRoom = e;
}

void AdventureTime::Player::addItem(int item)
{
	inventory.push_back(item);
}

void AdventureTime::Player::removeItem(int item)
{
	inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());
}

std::vector<int> AdventureTime::Player::getItems() const {
	return inventory;
}

std::vector<int> AdventureTime::Player::getEquipped() const {
	return equipped;
}

void AdventureTime::Player::equip(int id) {
	if (std::find(inventory.begin(), inventory.end(), id) != inventory.end()) {
		equipped.push_back(id);
		inventory.erase(std::remove(inventory.begin(), inventory.end(), id), inventory.end());
	}
	else {
		std::cout << "Not in inventory";
	}
}

void AdventureTime::Player::unequip(int id) {
	equipped.erase(std::remove(equipped.begin(), equipped.end(), id), equipped.end());
}