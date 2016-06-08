//#include "stdafx.h"
#include "Indoors.h"

AdventureTime::Indoors::Indoors(std::string && description, int itemId, bool equipped) : 
Environment(std::move(description)),
Locked(itemId, equipped)
{
}


std::string AdventureTime::Indoors::getDescription() const {
	return description;
}

