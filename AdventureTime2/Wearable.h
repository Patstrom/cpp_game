#pragma once
#include <string>
#include "Item.h"

namespace AdventureTime {
	class Wearable :
		public virtual Item
	{
	public:
		Wearable(std::string && description);
	};
}
