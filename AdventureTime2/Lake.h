#pragma once
#include "Environment.h"
namespace AdventureTime{
	class Lake :
		public Environment
	{
	public:
		Lake(std::string & desc);
		~Lake();
	};
}
