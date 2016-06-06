#include "Game.h"
#include <iostream>
#include <string>

void AdventureTime::Game::goToRoom(const Command c) 
{
	if (!c.hasSecondWord()) {
		std::cout << "Where to?\n";
		findRoom(player.getCurrentRoom()).printDirections();
		return;
	}

	const std::string direction = c.getSecondWord();
	auto newRoom = findRoom(player.getCurrentRoom()).getNextRoom(direction);
	player.setCurrentRoom(newRoom);
	std::cout << findRoom(newRoom).getDescription();
}

AdventureTime::Environment & AdventureTime::Game::findRoom(int ID)
{
	for (auto it = environments.begin(); it != environments.end(); it++) {
		if (it->getID() == ID)
			return *it;
	}
}


bool AdventureTime::Game::processCommand(const Command c)
{
	if (c.isUnknown()) {
		std::cout << "Command does not exist";
		return false;
	}

	const std::string commandWord = c.getCommandWord();
	if (commandWord.compare("help") == 0) {
		std::cout << "Available commands: \n";
		parser.showCommands();
		return false;
	}
	else if (commandWord.compare("go") == 0) {
		goToRoom(c);
		return false;
	}
	else if (commandWord.compare("quit") == 0) {
		std::cout << "Thank you come again!";
		return true;
	}

	return false; //Command not registered
}

AdventureTime::Game::Game() 
{
	environments = mg.generate_map();
	std::cout << "Welcome to game!\n\n" << findRoom(player.getCurrentRoom()).getDescription() << "\n";
}


AdventureTime::Game::~Game()
{
}

void AdventureTime::Game::play()
{
	bool finished = false;
	while (!finished) {
		std::cout << ">"; //Prompt

		Command c = parser.getCommand();
		finished = processCommand(c);

		std::cout << "\n";
	}
}

