#pragma once
#include "Environment.h"
#include "Item.h"
#include "Actor.h"
#include "Player.h"
#include <memory>
#include <string>

namespace AdventureTime {
	class MapGenerator
	{
	private:
	public:
		MapGenerator();
		~MapGenerator();
		std::vector<std::shared_ptr<Environment>> generate_environments();
		std::vector<std::shared_ptr<Item>> generate_items();
		std::vector<std::shared_ptr<Actor>> generate_actors();
	};
}