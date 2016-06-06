#pragma once
#include "Environment.h"
namespace AdventureTime {
	class Indoors :
		public Environment
	{
	public:
		Indoors(std::string & description);
		~Indoors();
		virtual std::string getDescription() const;
		virtual const bool isIndoors() const;
	};
}