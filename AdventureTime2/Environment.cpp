#include "Environment.h"

std::atomic<int> AdventureTime::Environment::s_id;

AdventureTime::Environment::Environment(std::string && desc) :
id(++s_id),
description(desc)
{
}

std::string AdventureTime::Environment::getDescription() const
{
	return description;
}

void AdventureTime::Environment::removeItem(int item)
{
	items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

void AdventureTime::Environment::addItem(int item)
{
	items.push_back(item);
}

int AdventureTime::Environment::getID() const
{
	return id;
}

void AdventureTime::Environment::addDirection(std::string s, int ID)
{
	directions[s] = ID;
}

void AdventureTime::Environment::printDirections()
{
	for (auto it = directions.begin(); it != directions.end(); it++) {
		std::cout << it -> first << " ";
	}
}

std::vector<int> AdventureTime::Environment::getItems() {
	return items;
}

int AdventureTime::Environment::getNextRoom(const std::string direction)
{
	return directions[direction];
}
