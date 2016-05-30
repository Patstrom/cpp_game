#pragma once
#include "MapGenerator.h"
#include "parser.h"
#include "Player.h"


namespace AdventureTime {
	class Game
	{
	private:
		int time;
		MapGenerator mg;
		parser parser;
		Player player;
		bool processCommand(const Command c);
		void goToRoom(const Command c);
		Environment & findRoom(int ID);
		std::vector<Environment> environments;
	public:
		Game();
		~Game();
		void play();
	};
}
