#pragma once
#include "MapGenerator.h"
#include "Outdoors.h"
#include "Indoors.h"

std::vector<std::shared_ptr<AdventureTime::Environment>> AdventureTime::MapGenerator::generate_environments()
{
	std::vector<std::shared_ptr<Environment>> tempList;

	std::shared_ptr<Environment> park(new Outdoors(std::string("The park!!! :D"), 10));
	std::shared_ptr<Environment> parkingLot(new Outdoors(std::string("The parking lot"), 10));
	std::shared_ptr<Environment> lake(new Outdoors(std::string("The lake by the park"), 10));
	std::shared_ptr<Environment> cafe(new Indoors(std::string("The cafeteria")));
	std::shared_ptr<Environment> apartment(new Indoors(std::string("You follow a residence into the apartment complex")));

	park->addDirection("north", parkingLot->getID());
	park->addDirection("south", lake->getID());
	park->addDirection("west", parkingLot->getID());
	park->addDirection("east", cafe->getID());

	parkingLot->addDirection("north", apartment->getID());



	tempList.push_back(park);
	tempList.push_back(parkingLot);
	tempList.push_back(lake);
	tempList.push_back(cafe);
	tempList.push_back(apartment);
	return tempList;
}

void AdventureTime::MapGenerator::generate_paths()
{

}

void AdventureTime::MapGenerator::generate_actors()
{

}

AdventureTime::MapGenerator::MapGenerator()
{

}

AdventureTime::MapGenerator::~MapGenerator()
{

}

std::vector<std::shared_ptr<AdventureTime::Environment>> AdventureTime::MapGenerator::generate_map()
{
	return generate_environments();
}
