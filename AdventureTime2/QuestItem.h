#pragma once
#include "Item.h"
namespace AdventureTime {
	class QuestItem :
		public virtual Item
	{
	private:
		std::string special;
	public:
		QuestItem(std::string && description, std::string && special);
		virtual void use();
		virtual std::string getDescription() const;
	};
}