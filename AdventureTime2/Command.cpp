#include "Command.h"


AdventureTime::Command::Command(const std::string & first, const std::string & second):
commandWord(first),
secondWord(second)
{
}

AdventureTime::Command::~Command()
{

}

const std::string AdventureTime::Command::getCommandWord() const
{
	return commandWord;
}

const std::string AdventureTime::Command::getSecondWord() const
{
	return secondWord;
}

const bool  AdventureTime::Command::isUnknown() const
{
	return commandWord.empty();
}

const bool AdventureTime::Command::hasSecondWord() const
{
	return !secondWord.empty();
}
