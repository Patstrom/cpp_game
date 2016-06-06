#pragma once
#include "Environment.h"
#include <memory>

namespace AdventureTime {
	class MapGenerator
	{
	private:
		std::vector<std::shared_ptr<Environment>> generate_environments();
		void generate_paths();
		void generate_actors();
	public:
		MapGenerator();
		~MapGenerator();
		std::vector<std::shared_ptr<Environment>> generate_map(); //Generera kartan
	};
}