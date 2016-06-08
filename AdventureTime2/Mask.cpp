//#include "stdafx.h"
#include "Mask.h"


AdventureTime::Mask::Mask(std::string && description, std::string && special) :
Item(std::string("mask"), std::move(description)),
QuestItem(std::move(description),std::move(special)),
Wearable(std::move(description))
{
}

void AdventureTime::Mask::use() {
	std::cout << "Nothing in particular happens";
}
