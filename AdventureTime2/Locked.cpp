#include "stdafx.h"
#include "Locked.h"


AdventureTime::Locked::Locked(int id) :
itemId(id)
{
}

int AdventureTime::Locked::getItemId() const {
	return itemId;
}

