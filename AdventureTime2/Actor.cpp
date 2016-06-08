#include "Actor.h"

AdventureTime::Actor::Actor(std::string name) :
name(name), finished(false)
{

}

bool AdventureTime::Actor::isFinished() const {
	return finished;
}

void AdventureTime::Actor::setCurrentRoom(std::weak_ptr<AdventureTime::Environment> e)
{
	std::weak_ptr<Actor> actor_ptr = shared_from_this();
	e.lock()->addActor(actor_ptr);
	auto currentRoomLocked = currentRoom.lock();
	if (currentRoomLocked != 0)
		currentRoomLocked->removeActor(actor_ptr);
	currentRoom = e;
}

std::string AdventureTime::Actor::getName() const
{
	return name;
}