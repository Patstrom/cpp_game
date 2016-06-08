#include "Stick.h"


AdventureTime::Stick::Stick(std::string && description, std::string && special) :
Item(std::string("stick"), std::move(description)),
QuestItem(std::move(description),std::move(special))
{
}

void AdventureTime::Stick::use() {
	std::cout << "Nothing in particular happens";
}
