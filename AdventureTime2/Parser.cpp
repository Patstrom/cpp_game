#include "Parser.h"

AdventureTime::Parser::Parser()
{
	valid_commands = { "help", "go", "pick", "use", "equip", "inventory", "equipped", "quit" };
}


AdventureTime::Command AdventureTime::Parser::getCommand()
{
	std::string inputLine;
	getline(std::cin, inputLine);
	std::transform(inputLine.begin(), inputLine.end(), inputLine.begin(), ::tolower);

	std::string cword;
	std::string sword;

	std::size_t found = inputLine.find(" ");
	if (found != std::string::npos) {
		cword = inputLine.substr(0, found);
		sword = inputLine.substr(found+1);
	}
	else {
		cword = inputLine;
	}

	for (auto i = valid_commands.begin(); i != valid_commands.end(); i++)
		if (*i == cword)
			return Command(cword, sword);

	// Not a valid command!
	return Command("", "");
}

void AdventureTime::Parser::showCommands() const
{
	for (auto i = valid_commands.begin(); i != valid_commands.end(); i++) {
		std::cout << "\t" << *i << "\n";
	}
}