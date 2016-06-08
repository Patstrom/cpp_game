#include "Actor.h"

AdventureTime::Actor::Actor(std::string name) :
name(name), finished(false)
{

}

bool AdventureTime::Actor::isFinished() const {
	return finished;
}

void AdventureTime::Actor::setCurrentRoom(std::shared_ptr<AdventureTime::Environment> e)
{
	std::shared_ptr<Actor> actor_ptr(this);
	e->addActor(actor_ptr);
	if (currentRoom != 0)
		currentRoom->removeActor(actor_ptr);
	currentRoom = e;
}

std::string AdventureTime::Actor::getName() const
{
	return name;
}