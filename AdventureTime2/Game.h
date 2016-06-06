#pragma once
#include "MapGenerator.h"
#include "parser.h"
#include "Player.h"
#include <memory>
#include <string>
#include <iostream>


namespace AdventureTime {
	class Game
	{
	private:
		int time;
		MapGenerator mg;
		parser parser;
		Player player;
		bool processCommand(const Command & c);
		void goToRoom(const Command & c);
		Environment & findRoom(int ID);
		void pickUp(const Command & c);
		std::vector<std::shared_ptr<Item>> findItems(std::vector<int> list);
		void useItem(const Command & c);
		void equipItem(const Command & c);
		std::vector<std::shared_ptr<Environment>> environments;
		std::vector<std::shared_ptr<Item>> items;
	public:
		Game();
		~Game() = default;
		void play();
	};
}
