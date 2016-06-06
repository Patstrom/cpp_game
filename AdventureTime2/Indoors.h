#pragma once
#include "Environment.h"
#include "Locked.h"
namespace AdventureTime {
	class Indoors :
		public Environment,
		public Locked
	{
	public:
		Indoors(std::string && description, int itemId);
		virtual std::string getDescription() const;
	};
}