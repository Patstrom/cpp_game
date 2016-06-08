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

void AdventureTime::Player::addItem(std::weak_ptr<AdventureTime::Item> item)
{
	inventory.push_back(item);
}

void AdventureTime::Player::removeItem(std::weak_ptr<AdventureTime::Item> item)
{
	inventory.erase(std::remove_if(inventory.begin(), inventory.end(),
		[item] (std::weak_ptr<Item> otherItem) {return item.lock() == otherItem.lock();}), inventory.end());
}

std::vector<std::weak_ptr<AdventureTime::Item>> AdventureTime::Player::getItems() const {
	return inventory;
}

std::vector<std::weak_ptr<AdventureTime::Item>> AdventureTime::Player::getEquipped() const {
	return equipped;
}

void AdventureTime::Player::equip(std::weak_ptr<AdventureTime::Item> item) {
	//if (std::find(inventory.begin(), inventory.end(), item) != inventory.end()) { // If the item exists in the inventory
	if (std::find_if(inventory.begin(), inventory.end(), [item] (std::weak_ptr<Item> toCompare) {return toCompare.lock() == item.lock();}) != inventory.end()) {
		//std::cout << item->getDescription() << " found in inventory\n";
		if (equipped.size() != 0) {
			equipped.erase(equipped.begin());
		}
		equipped.push_back(item);
		removeItem(item);
	}
	else {
		std::cout << "Not in inventory";
	}
}

void AdventureTime::Player::unequip(std::weak_ptr<AdventureTime::Item> item) {
	equipped.erase(std::remove_if(equipped.begin(), equipped.end(), 
		[item] (std::weak_ptr<Item> otherItem) {return item.lock() == otherItem.lock();}), equipped.end());
}

void AdventureTime::Player::printLocationDetails() const {
	auto currentRoomLocked = currentRoom.lock();
	std::cout << "[Location] " << currentRoomLocked->getDescription() << "\n";
	std::cout << "[Items] ";
	for (std::weak_ptr<Item> i : currentRoomLocked->getItems())
			std::cout << i.lock()->getType() << ", ";
	std::cout << "\n";
	if (currentRoomLocked->getActors().size() != 0) {
		std::cout << "[Characters] ";
		for (std::weak_ptr<Actor> a : currentRoomLocked->getActors())
			std::cout << a.lock()->getName() << ", ";
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
	auto currentRoomLocked = currentRoom.lock();
	if (!c.hasSecondWord()) {
		std::cout << "Where to?\n";
		currentRoomLocked->printDirections();
		return false;
	}

	const std::string direction = c.getSecondWord();
	if (!currentRoomLocked->hasDirection(direction)) {
		std::cout << "Invalid direction!\n";
		return false;
	}

	std::shared_ptr<AdventureTime::Environment> nextRoom = (currentRoomLocked->getNextRoom(direction)).lock();

	//If room is locked
	if (Locked * lockedRoom = dynamic_cast<Locked*>(&(*nextRoom))) {
		if (lockedRoom->isUnlocked()) {
			setCurrentRoom(nextRoom);
			return true;
		}
		int key = lockedRoom->getItemId();
		std::vector<std::weak_ptr<AdventureTime::Item>> items;
		if (lockedRoom->needsEquipped()) {
			items = getEquipped();
		}
		else {
			items = getItems();
		}
		for (auto it = items.begin(); it != items.end(); it++) {
			if ((*it).lock()->getId() == key){
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
	auto currentRoomLocked = currentRoom.lock();
	std::vector<std::weak_ptr<Item>> nearbyItems = currentRoomLocked->getItems();

	if (!c.hasSecondWord()) {
		std::cout << "pick up what?\n";
		for (std::weak_ptr<Item> i : nearbyItems)
			std::cout << i.lock()->getType() << " ";
		return;
	}

	const std::string type = c.getSecondWord();
	for (std::weak_ptr<Item> i : nearbyItems) {
		auto item = i.lock();
		if (item->getType().compare(type) == 0) {
			addItem(i);
			std::cout << item->getDescription();
			currentRoomLocked->removeItem(i);
			break;
		}
	}
}

bool AdventureTime::Player::useItem(const Command & c) {
	if (!c.hasSecondWord()) {
		std::cout << "Use what item?\n";
		for (std::weak_ptr<Item> i : inventory) {
			std::cout << i.lock()->getType() << ", ";
		}
		return false;
	}

	std::string type = c.getSecondWord();
	for (std::weak_ptr<Item> i : inventory) {
		auto item = i.lock();
		if (item->getType().compare(type) == 0) {
			auto currentRoomLocked = currentRoom.lock();
			// TODO: How to do this now???
			if (item->getId() == 3 && currentRoomLocked->getActors().size() > 1) {
				std::cout << "Master is happy! Huge success!";
				getchar();
				finished = true;
				return true;
			}
			item->use();
		}
	}
	return false;
}

void AdventureTime::Player::equipItem(const Command & c) {
	if (!c.hasSecondWord()) {
		std::cout << "Which item?\n";
		for (std::weak_ptr<Item> i : inventory) {
			if (Wearable * wearableItem = dynamic_cast<Wearable*>(&*i.lock())) {
				std::cout << wearableItem->getType() << ", ";
			}
		}
		return;
	}

	std::string type = c.getSecondWord();
	for (std::weak_ptr<Item> i : inventory) {
		if (dynamic_cast<Wearable*>(&*i.lock())) {
			equip(i);
			std::cout << "Successfully equipped!";
			return;
		}
	}

}

void AdventureTime::Player::showInventory() const {
	for (std::weak_ptr<Item> t : inventory) {
		std::cout << t.lock()->getType() << ", ";
	}
}

void AdventureTime::Player::showEquipped() const {
	for (std::weak_ptr<Item> t : equipped) {
		std::cout << t.lock()->getType() << ", ";
	}
}

void AdventureTime::Player::help() const {
	auto currentRoomLocked = currentRoom.lock();
	std::cout << "Available commands: \n";
	parser.showCommands();
	std::cout << "\nCurrent location:\n\t" << currentRoomLocked->getDescription();
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
		return useItem(c);
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