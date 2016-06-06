#include "Item.h"

std::atomic<int> AdventureTime::Item::s_id;

AdventureTime::Item::Item(std::string type, std::string && description) :
id(++s_id),
type(type),
description(description)
{
}


int AdventureTime::Item::getId() const {
	return id;
}

std::string AdventureTime::Item::getType() const{
	return type;
}

std::string AdventureTime::Item::getDescription() const {
	return description;
}