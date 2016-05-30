#pragma once
#include "Environment.h"

namespace AdventureTime {
	class Park :
		public Environment
	{
	public:
		Park(std::string & desc);
		~Park();
	};
}
