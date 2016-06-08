#include "Key.h"


AdventureTime::Key::Key(std::string && description, std::string && special) :
Item(std::string("key"), std::move(description)),
QuestItem(std::move(description),std::move(special))
{
}

void AdventureTime::Key::use() {
	std::cout << "Nothing in particular happens";
}
