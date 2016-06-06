#include "MapGenerator.h"
#include <string>
#include "Outdoors.h"
#include "Indoors.h"

std::vector<AdventureTime::Environment> AdventureTime::MapGenerator::generate_environments()
{
	std::vector<Environment> tempList;

	Outdoors park(std::string("The park!!! :D"), 10);
	Outdoors parkingLot(std::string("The parking lot"), 10);
	Outdoors lake(std::string("The lake by the park"), 10);
	Indoors cafe(std::string("The cafeteria"));
	Indoors apartment(std::string("You follow a residence into the apartment complex"));

	park.addDirection("north", parkingLot.getID());
	park.addDirection("south", lake.getID());
	park.addDirection("west", parkingLot.getID());
	park.addDirection("east", cafe.getID());

	parkingLot.addDirection("north", apartment.getID());



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

std::vector<AdventureTime::Environment> AdventureTime::MapGenerator::generate_map()
{
	return generate_environments();
}
