#pragma once	
#include "Game.h"
#include "Locked.h"
#include "Wearable.h"

void AdventureTime::Game::goToRoom(const Command & c)
{
	auto possibleDirections = findRoom(player.getCurrentRoom()).getDirections();
	if (!c.hasSecondWord()) {
		std::cout << "Where to?\n";
		for (auto t: possibleDirections) {
			std::cout << t << " ";
		}
		return;
	}

	const std::string direction = c.getSecondWord();
	if (std::find(possibleDirections.begin(), possibleDirections.end(), direction) == possibleDirections.end()) {
		std::cout << "Invalid direction!\n";
		return;
	}

	int nextRoomId = findRoom(player.getCurrentRoom()).getNextRoom(direction);
	Environment & nextRoom = findRoom(nextRoomId);
	//If room is locked
	if (Locked * lockedRoom = dynamic_cast<Locked*>(&nextRoom)) {
		if (lockedRoom->isUnlocked()) {
			player.setCurrentRoom(nextRoomId);
			std::cout << nextRoom.getDescription();
			return;
		}
		auto key = lockedRoom->getItemId();
		std::vector<std::shared_ptr<Item>> items;
		if (lockedRoom->needsEquipped()) {
			items = findItems(player.getEquipped());
		}
		else {
			items = findItems(player.getItems());
		}
		for (auto it = items.begin(); it != items.end(); it++) {
			if ((*it)->getId() == key){
				player.setCurrentRoom(nextRoomId);
				lockedRoom->unlock();
				if (lockedRoom->needsEquipped()) {
					player.unequip(key);
				}
				else {
					player.removeItem(key);
				}
				std::cout << nextRoom.getDescription();
				return;
			}
		}
		std::cout << "Oh no, you are missing the item required to enter";
	}
	//If room isn't unlocked
	else {
		player.setCurrentRoom(nextRoomId);
		std::cout << nextRoom.getDescription();
	}
}

AdventureTime::Environment & AdventureTime::Game::findRoom(int ID)
{
	for (auto it = environments.begin(); it != environments.end(); it++) {
		if ((*it)->getID() == ID)
			return **it;
	}
}

void AdventureTime::Game::pickUp(const Command & c) {
	Environment & currentRoom = findRoom(player.getCurrentRoom());
	auto nearbyItems = findItems(currentRoom.getItems());

	if (!c.hasSecondWord()) {
		std::cout << "pick up what?\n";
		for (auto i : nearbyItems)
			std::cout << i->getType() << " ";
		return;
	}

	const std::string type = c.getSecondWord();
	for (auto i : nearbyItems) {
		if (i->getType().compare(type) == 0) {
			player.addItem(i->getId());
			std::cout << i->getDescription();
			currentRoom.removeItem(i->getId());
			break;
		}
	}
}

std::vector<std::shared_ptr<AdventureTime::Item>> AdventureTime::Game::findItems(std::vector<int> list) {
	std::vector<std::shared_ptr<Item>> tempList;

	for (auto i = items.begin(); i != items.end(); i++) {
		for (auto j = list.begin(); j != list.end(); j++) {
			if ((*i)->getId() == *j) {
				tempList.push_back(*i);
			}
		}
	}
	return tempList;
}

void AdventureTime::Game::useItem(const Command & c) {
	auto inventory = findItems(player.getItems());
	
	if (!c.hasSecondWord()) {
		std::cout << "Use what item?\n";
		for (auto i : inventory) {
			std::cout << i->getType() << " ";
		}
		return;
	}

	std::string type = c.getSecondWord();
	for (auto i : inventory) {
		if (i->getType().compare(type) == 0) {
			if (i->getId() == 3 && player.getCurrentRoom() == 1) {
				std::cout << "Master is happy! Huge success!";
				getchar();
				exit(0);
			}
			i->use();
		}
	}
}

void AdventureTime::Game::equipItem(const Command & c) {
	auto inventory = findItems(player.getItems());

	if (!c.hasSecondWord()) {
		std::cout << "Which item?\n";
		for (auto i : inventory) {
			if (Wearable * wearableItem = dynamic_cast<Wearable*>(&*i)) {
				std::cout << i->getType() << " ";
			}
		}
		return;
	}

	std::string type = c.getSecondWord();
	for (auto i : inventory) {
		if (Wearable * wearableItem = dynamic_cast<Wearable*>(&*i)) {
			int id = wearableItem->getId();
			player.equip(id);
			std::cout << "Successfully equipped!";
			return;
		}
	}

}

bool AdventureTime::Game::processCommand(const Command & c)
{
	if (c.isUnknown()) {
		std::cout << "Command does not exist";
		return false;
	}

	const std::string commandWord = c.getCommandWord();
	if (commandWord.compare("help") == 0) {
		std::cout << "Available commands: \n";
		parser.showCommands();
		return false;
	}
	else if (commandWord.compare("go") == 0) {
		goToRoom(c);
		return false;
	}
	else if (commandWord.compare("pick") == 0) {
		pickUp(c);
	}
	else if (commandWord.compare("use") == 0) {
		useItem(c);
	}
	else if (commandWord.compare("equip") == 0) {
		equipItem(c);
	}
	else if (commandWord.compare("inventory") == 0) {
		auto tmp = findItems(player.getItems());
		for (auto t : tmp) {
			std::cout << t->getType() << " ";
		}
	}
	else if (commandWord.compare("equipped") == 0) {
		auto tmp = findItems(player.getEquipped());
		for (auto t : tmp) {
			std::cout << t->getType() << " ";
		}
	}
	else if (commandWord.compare("quit") == 0) {
		std::cout << "Thank you come again!";
		return true;
	}

	return false; //Command not registered
}

AdventureTime::Game::Game()
{
	environments = mg.generate_environments();
	items = mg.generate_items();

	findRoom(3).addItem(1); //Add mask to lake
	findRoom(4).addItem(2); //Add key to cafe
	findRoom(5).addItem(3); //Add stick to apartment
	findRoom(2).addItem(4); //Add ball to parkingLot
	findRoom(2).addItem(5); //Add the other ball to parkingLot

	std::cout << "Welcome to game!\n\n" << findRoom(player.getCurrentRoom()).getDescription() << "\n";
}



void AdventureTime::Game::play()
{
	bool finished = false;
	while (!finished) {
		std::cout << ">"; //Prompt

		Command c = parser.getCommand();
		finished = processCommand(c);

		std::cout << "\n";
	}
}

