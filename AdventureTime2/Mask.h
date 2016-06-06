#pragma once
#include "Item.h"
#include "Wearable.h"
#include "QuestItem.h"

namespace AdventureTime {
	class Mask :
		public QuestItem,
		public Wearable
	{
	public:
		Mask(std::string && description, std::string && special);
		void use();
	};
}