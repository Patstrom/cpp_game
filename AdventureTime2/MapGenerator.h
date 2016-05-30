#pragma once
#include "Environment.h"

namespace AdventureTime {
	class MapGenerator
	{
	private:
		std::vector<Environment> generate_environments();
		void generate_paths();
		void generate_actors();
	public:
		MapGenerator();
		~MapGenerator();
		std::vector<Environment> generate_map(); //Generera kartan
	};
}