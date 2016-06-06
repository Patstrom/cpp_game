#pragma once
#include "MapGenerator.h"
#include "Outdoors.h"
#include "Indoors.h"
#include "Item.h"
#include "Mask.h"
#include "Ball.h"


std::vector<std::shared_ptr<AdventureTime::Environment>> AdventureTime::MapGenerator::generate_environments()
{
	std::vector<std::shared_ptr<Environment>> tempList;

	std::shared_ptr<Environment> park(new Outdoors(std::string("The park!!! :D"), 50));
	std::shared_ptr<Environment> parkingLot(new Outdoors(std::string("The parking lot"), 10));
	std::shared_ptr<Environment> lake(new Outdoors(std::string("The lake by the park"), 10));
	std::shared_ptr<Environment> cafe(new Indoors(std::string("The cafeteria"), 1));
	std::shared_ptr<Environment> apartment(new Indoors(
		std::string("You follow a residence into the apartment complex"), 2));

	park->addDirection("north", parkingLot->getID());
	park->addDirection("south", lake->getID());
	park->addDirection("west", parkingLot->getID());
	park->addDirection("east", cafe->getID());

	parkingLot->addDirection("north", apartment->getID());
	parkingLot->addDirection("south", park->getID());

	lake->addDirection("north", park->getID());

	cafe->addDirection("west", park->getID());

	apartment->addDirection("south", parkingLot->getID());

	tempList.push_back(park);
	tempList.push_back(parkingLot);
	tempList.push_back(lake);
	tempList.push_back(cafe);
	tempList.push_back(apartment);
	return tempList;
}

std::vector<std::shared_ptr<AdventureTime::Item>> AdventureTime::MapGenerator::generate_items() 
{
	std::vector<std::shared_ptr<Item>> tempList;

	std::shared_ptr<Item> human_mask(new Mask(std::string("A mask with a human face"),
		std::string("This might allow you to enter the cafe!")));

	std::shared_ptr<Item> key(new QuestItem(std::string("A key!"),
		std::string("This might open the apartment")));

	std::shared_ptr<Item> stick(new QuestItem(std::string("A extraordinary, super duper fun stick!"),
		std::string("Bring it to master!!")));

	std::shared_ptr<Item> ball(new Ball(std::string("A regular, super fun ball!!")));
	std::shared_ptr<Item> ball1(new Ball(std::string("A regular, not so fun ball")));
	

	tempList.push_back(human_mask);
	tempList.push_back(key);
	tempList.push_back(stick);
	tempList.push_back(ball);
	tempList.push_back(ball1);

	return tempList;
}

void AdventureTime::MapGenerator::generate_actors()
{

}

AdventureTime::MapGenerator::MapGenerator()
{

}

AdventureTime::MapGenerator::~MapGenerator() {

}
