#pragma once
#include "Item.h"
#include "QuestItem.h"

namespace AdventureTime {
	class Stick :
		public QuestItem
	{
	public:
		Stick(std::string && description, std::string && special);
		void use();
	};
}