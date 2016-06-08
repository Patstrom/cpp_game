#include "Master.h"

AdventureTime::Master::Master() : Actor("Master")
{
}


void AdventureTime::Master::act() {
	srand(time(NULL));
	int i = (std::rand() % 3);
	if (i == WALK) {
		std::vector<std::weak_ptr<Environment>> neighbors = currentRoom.lock()->getNeighbors();
		std::shared_ptr<Environment> nextRoom = (neighbors[(std::rand() % neighbors.size())]).lock();
		setCurrentRoom(nextRoom);
	} else { // Do nothing

	}
}