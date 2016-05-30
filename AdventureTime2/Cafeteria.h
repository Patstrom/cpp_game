#pragma once
#include "Environment.h"
namespace AdventureTime {
	class Cafeteria :
		public Environment
	{
	public:
		Cafeteria(std::string & desc);
		~Cafeteria();
	};
}
