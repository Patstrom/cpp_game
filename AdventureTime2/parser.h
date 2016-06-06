#pragma once
#include "Command.h"
#include <iostream>
#include <string>
#include <algorithm>

namespace AdventureTime {
	class parser
	{
	private:
		std::vector<std::string> valid_commands;
	public:
		parser();
		~parser() = default;
		Command getCommand();
		void showCommands() const;
	};
}
