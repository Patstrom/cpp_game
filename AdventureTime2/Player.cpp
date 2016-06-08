#include "Player.h"
#include "Locked.h"
#include "Wearable.h"


AdventureTime::Player::Player() : Actor("You")
{
}


void AdventureTime::Player::setPlayerName(const std::string s)
{
	playerName = s;
}

void AdventureTime::Player::addItem(std::shared_ptr<AdventureTime::Item> item)
{
	inventory.push_back(item);
}

void AdventureTime::Player::removeItem(std::shared_ptr<AdventureTime::Item> item)
{
	inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());
}

std::vector<std::shared_ptr<AdventureTime::Item>> AdventureTime::Player::getItems() const {
	return inventory;
}

std::vector<std::shared_ptr<AdventureTime::Item>> AdventureTime::Player::getEquipped() const {
	return equipped;
}

void AdventureTime::Player::equip(std::shared_ptr<AdventureTime::Item> item) {
	if (std::find(inventory.begin(), inventory.end(), item) != inventory.end()) { // If the item exists in the inventory
		//std::cout << item->getDescription() << " found in inventory\n";
		if (equipped.size() != 0) {
			equipped.erase(equipped.begin());
		}
		equipped.push_back(item);
	}
	else {
		std::cout << "Not in inventory";
	}
}

void AdventureTime::Player::unequip(std::shared_ptr<AdventureTime::Item> item) {
	equipped.erase(std::remove(equipped.begin(), equipped.end(), item), equipped.end());
}

void AdventureTime::Player::printLocationDetails() const {
	std::cout << "[Location] " << currentRoom->getDescription() << "\n";
	std::cout << "[Items] ";
	for (std::shared_ptr<Item> i : currentRoom->getItems())
			std::cout << i->getType() << ", ";
	std::cout << "\n";
	if (currentRoom->getActors().size() != 0) {
		std::cout << "[Characters] ";
		for (std::shared_ptr<Actor> a : currentRoom->getActors())
			std::cout << a->getName() << ", ";
		std::cout << "\n";
	}
}

void AdventureTime::Player::act() {
	bool actFinished = false;
	printLocationDetails();

	while (!actFinished) {
		std::cout << ">"; //Prompt

		Command c = parser.getCommand();
		actFinished = processCommand(c);

		std::cout << "\n";
	}
}

bool AdventureTime::Player::goToRoom(const Command & c)
{
	if (!c.hasSecondWord()) {
		std::cout << "Where to?\n";
		currentRoom->printDirections();
		return false;
	}

	const std::string direction = c.getSecondWord();
	if (!currentRoom->hasDirection(direction)) {
		std::cout << "Invalid direction!\n";
		return false;
	}

	std::shared_ptr<AdventureTime::Environment> nextRoom = currentRoom->getNextRoom(direction);

	//If room is locked
	if (Locked * lockedRoom = dynamic_cast<Locked*>(&(*nextRoom))) {
		if (lockedRoom->isUnlocked()) {
			setCurrentRoom(nextRoom);
			return true;
		}
		int key = lockedRoom->getItemId();
		std::vector<std::shared_ptr<AdventureTime::Item>> items;
		if (lockedRoom->needsEquipped()) {
			items = getEquipped();
		}
		else {
			items = getItems();
		}
		for (auto it = items.begin(); it != items.end(); it++) {
			if ((*it)->getId() == key){
				setCurrentRoom(nextRoom);
				lockedRoom->unlock();
				if (lockedRoom->needsEquipped()) {
					unequip(*it);
				}
				else {
					removeItem(*it);
				}
				return true;
			}
		}
		std::cout << "Oh no, you are missing the item required to enter";
	}
	//If room isn't unlocked
	else {
		setCurrentRoom(nextRoom);
	}
	return true;
}

void AdventureTime::Player::pickUp(const Command & c) {
	std::vector<std::shared_ptr<Item>> nearbyItems = currentRoom->getItems();

	if (!c.hasSecondWord()) {
		std::cout << "pick up what?\n";
		for (std::shared_ptr<Item> i : nearbyItems)
			std::cout << i->getType() << " ";
		return;
	}

	const std::string type = c.getSecondWord();
	for (std::shared_ptr<Item> i : nearbyItems) {
		if (i->getType().compare(type) == 0) {
			addItem(i);
			std::cout << i->getDescription();
			currentRoom->removeItem(i);
			break;
		}
	}
}

void AdventureTime::Player::useItem(const Command & c) {	
	if (!c.hasSecondWord()) {
		std::cout << "Use what item?\n";
		for (std::shared_ptr<Item> i : inventory) {
			std::cout << i->getType() << ", ";
		}
		return;
	}

	std::string type = c.getSecondWord();
	for (std::shared_ptr<Item> i : inventory) {
		if (i->getType().compare(type) == 0) {
			// TODO: How to do this now???
			if (i->getId() == 3 && currentRoom->getActors().size() > 1) {
				std::cout << "Master is happy! Huge success!";
				getchar();
				exit(0);
			}
			i->use();
		}
	}
}

void AdventureTime::Player::equipItem(const Command & c) {
	if (!c.hasSecondWord()) {
		std::cout << "Which item?\n";
		for (std::shared_ptr<Item> i : inventory) {
			if (Wearable * wearableItem = dynamic_cast<Wearable*>(&*i)) {
				std::cout << wearableItem->getType() << ", ";
			}
		}
		return;
	}

	std::string type = c.getSecondWord();
	for (std::shared_ptr<Item> i : inventory) {
		if (dynamic_cast<Wearable*>(&*i)) {
			equip(i);
			std::cout << "Successfully equipped!";
			return;
		}
	}

}

void AdventureTime::Player::showInventory() const {
	for (std::shared_ptr<Item> t : inventory) {
		std::cout << t->getType() << ", ";
	}
}

void AdventureTime::Player::showEquipped() const {
	for (std::shared_ptr<Item> t : equipped) {
		std::cout << t->getType() << ", ";
	}
}

void AdventureTime::Player::help() const {
	std::cout << "Available commands: \n";
	parser.showCommands();
	std::cout << "\nCurrent location:\n\t" << currentRoom->getDescription();
}

bool AdventureTime::Player::processCommand(const Command & c)
{
	if (c.isUnknown()) {
		std::cout << "Command does not exist";
		return false;
	}

	const std::string commandWord = c.getCommandWord();
	
	if (commandWord.compare("help") == 0) {
		help();
	}
	else if (commandWord.compare("go") == 0) {
		return goToRoom(c);
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
		showInventory();
	}
	else if (commandWord.compare("equipped") == 0) {
		showEquipped();
	}
	else if (commandWord.compare("quit") == 0) {
		std::cout << "Thank you come again!";
		finished = true;
		return true;
	}

	return false;
}