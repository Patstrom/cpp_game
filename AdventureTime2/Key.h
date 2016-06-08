#pragma once
#include "Item.h"
#include "QuestItem.h"

namespace AdventureTime {
	class Key :
		public QuestItem
	{
	public:
		Key(std::string && description, std::string && special);
		void use();
	};
}