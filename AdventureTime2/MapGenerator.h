#pragma once
#include "Environment.h"
#include "Item.h"
#include <memory>
#include <string>

namespace AdventureTime {
	class MapGenerator
	{
	private:
		void generate_actors();
	public:
		MapGenerator();
		~MapGenerator();
		std::vector<std::shared_ptr<Environment>> generate_environments();
		std::vector<std::shared_ptr<Item>> generate_items();
	};
}