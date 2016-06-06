#pragma once
#include "Item.h"
namespace AdventureTime {
	class Ball :
		public Item
	{
	public:
		Ball(std::string && description);
		void use();
		virtual std::string getDescription() const;
	};
}
