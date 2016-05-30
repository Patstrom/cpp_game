#pragma once
#include <string>
#include <vector>

namespace AdventureTime {
	class Command
	{
	private:
		const std::string commandWord;
		const std::string secondWord;
	public:
		Command(const std::string & first, const std::string & second);
		~Command();
		const std::string getCommandWord() const;
		const std::string getSecondWord() const;
		const bool isUnknown() const;
		const bool hasSecondWord() const;
	};
}
