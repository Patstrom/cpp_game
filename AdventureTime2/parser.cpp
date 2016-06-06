#include "parser.h"

AdventureTime::parser::parser()
{
	valid_commands = { "help", "go", "pick", "use", "inventory", "quit" };
}


AdventureTime::Command AdventureTime::parser::getCommand()
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

	return Command(cword, sword);
}

void AdventureTime::parser::showCommands() const
{
	for (auto i = valid_commands.begin(); i != valid_commands.end(); i++) {
		std::cout << *i << " ";
	}
}