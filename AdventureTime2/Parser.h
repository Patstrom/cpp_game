#pragma once
#include "Command.h"
#include <iostream>
#include <string>
#include <algorithm>

namespace AdventureTime {
	class Parser
	{
	private:
		std::vector<std::string> valid_commands;
	public:
		Parser();
		~Parser() = default;
		Command getCommand();
		void showCommands() const;
	};
}
