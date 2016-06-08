#include "Game.h"

AdventureTime::Environment & AdventureTime::Game::findRoom(int ID) const
{
	for (auto it = environments.begin(); it != environments.end(); it++) {
		if ((*it)->getID() == ID)
			return **it;
	}
	//If here, ID isnt a valid room id
}

std::shared_ptr<AdventureTime::Item> AdventureTime::Game::findItem(int ID) const {

	for (auto i = items.begin(); i != items.end(); i++) {
		if ((*i)->getId() == ID) {
			return *i;
		}
	}
}

AdventureTime::Game::Game()
{
	environments = mg.generate_environments();
	items = mg.generate_items();
	actors = mg.generate_actors();

	/*Player * player = dynamic_cast<Player*>(&(*actors[0]));

	player->setCurrentRoom(environments[0]);*/
	for (std::shared_ptr<Actor> a : actors) {
		a->setCurrentRoom(environments[0]);
	}


	findRoom(3).addItem(findItem(1)); //Add mask to lake
	findRoom(4).addItem(findItem(2)); //Add key to cafe
	findRoom(5).addItem(findItem(3)); //Add stick to apartment
	findRoom(2).addItem(findItem(4)); //Add ball to parkingLot
	findRoom(2).addItem(findItem(5)); //Add the other ball to parkingLot

	std::cout << "Welcome to game!\n"; 
	std::cout << "You are a dog... [etc]\n";

	time = 0;
}



void AdventureTime::Game::play()
{
	bool finished = false;

	while (!finished) {
		for (std::shared_ptr<Actor> actor : actors)
		{
			actor->act();
			finished = actor->isFinished();
			if (finished)
				break;
		}
		time++;
	}
}

