#include "stdafx.h"
#include "Locked.h"


AdventureTime::Locked::Locked(int id, bool equipped) :
itemId(id),
equipped(equipped),
unlocked(false)
{
}

int AdventureTime::Locked::getItemId() const {
	return itemId;
}

bool AdventureTime::Locked::needsEquipped() const
{
	return equipped;
}

void AdventureTime::Locked::unlock() {
	unlocked = true;
}

bool AdventureTime::Locked::isUnlocked() const {
	return unlocked;
}