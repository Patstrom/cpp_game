#pragma once
#include "MapGenerator.h"
#include <memory>
#include <string>
#include <iostream>


namespace AdventureTime {
	class Game
	{
	private:
		int time;
		MapGenerator mg;
		std::vector<std::shared_ptr<Actor>> actors;
		std::vector<std::shared_ptr<Environment>> environments;
		std::vector<std::shared_ptr<Item>> items;
		Environment & findRoom(int ID) const;
		std::shared_ptr<Item> findItem(int ID) const;
	public:
		Game();
		~Game() = default;
		void play();
	};
}
