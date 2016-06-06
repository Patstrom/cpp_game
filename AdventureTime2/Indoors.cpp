#pragma once
#include "stdafx.h"
#include "Indoors.h"

AdventureTime::Indoors::Indoors(std::string && description, int itemId) : 
Environment(std::move(description)),
Locked(itemId)
{
}


std::string AdventureTime::Indoors::getDescription() const {
	return description;
}

