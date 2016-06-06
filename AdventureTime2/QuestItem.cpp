#include "stdafx.h"
#include "QuestItem.h"


AdventureTime::QuestItem::QuestItem(std::string && description, std::string && special) :
Item(std::string("questitem"), std::move(description)),
special(special)
{
}

std::string AdventureTime::QuestItem::getDescription() const {
	std::string temp = description;
	temp += "\n";
	temp.append(special);
	return temp;
}

void AdventureTime::QuestItem::use() {
	std::cout << special;
}