#pragma once
#include "Environment.h"
#include <ctime>

namespace AdventureTime {
	class Outdoors :
		public Environment
	{
	private:
		int chance_of_rain;
	public:
		Outdoors(std::string & description, int chance_of_rain);
		~Outdoors();
		virtual std::string getDescription() const;
		virtual const bool isIndoors() const;
	};
}