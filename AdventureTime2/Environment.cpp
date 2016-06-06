#include "Environment.h"

std::atomic<int> AdventureTime::Environment::s_id;

AdventureTime::Environment::Environment(std::string & desc) :
id(++s_id),
description(desc)
{
}

std::string AdventureTime::Environment::getDescription() const
{
	return description;
}

void AdventureTime::Environment::removeItem(Item item)
{

}

void AdventureTime::Environment::addItem(Item item)
{

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

int AdventureTime::Environment::getNextRoom(const std::string direction)
{
	return directions[direction];
}
