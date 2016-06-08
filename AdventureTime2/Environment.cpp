#include "Environment.h"
#include "Actor.h"

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

void AdventureTime::Environment::removeItem(std::shared_ptr<AdventureTime::Item> item)
{
	items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

void AdventureTime::Environment::addItem(std::shared_ptr<AdventureTime::Item> item)
{
	items.push_back(item);
}

int AdventureTime::Environment::getID() const
{
	return id;
}

void AdventureTime::Environment::addDirection(std::string s, std::shared_ptr<AdventureTime::Environment> environment)
{
	directions[s] = environment;
}

void AdventureTime::Environment::printDirections()
{
	for (auto it = directions.begin(); it != directions.end(); it++) {
		std::cout << it -> first << " ";
	}
}

std::vector<std::shared_ptr<AdventureTime::Item>> AdventureTime::Environment::getItems() {
	return items;
}

std::shared_ptr<AdventureTime::Environment> AdventureTime::Environment::getNextRoom(const std::string direction)
{
	return directions[direction];
}

bool AdventureTime::Environment::hasDirection(const std::string direction) const
{
	return directions.find(direction) != directions.end();
}

std::vector<std::shared_ptr<AdventureTime::Environment>> AdventureTime::Environment::getNeighbors() {
	std::vector<std::shared_ptr<Environment>> valueList;
	for (auto m : directions) {
		valueList.push_back(m.second);
	}
	return valueList;
}

void AdventureTime::Environment::addActor(std::shared_ptr<AdventureTime::Actor> actor) {
	actors.push_back(actor);
}

std::vector<std::shared_ptr<AdventureTime::Actor>> AdventureTime::Environment::getActors() {
	return actors;
}

void AdventureTime::Environment::removeActor(std::shared_ptr<AdventureTime::Actor> actor) {
	//actors.erase(std::remove(actors.begin(), actors.end(), actor), actors.end());
	std::cout << "HEJ" << std::endl;
	for (auto it = actors.begin(); it != actors.end(); ++it)
	{
		if (*it == actor) {
			actors.erase(it);
			return;
		}
	}
	std::cout << "HEJ" << std::endl;
}