#pragma once
#include "Environment.h"
namespace AdventureTime {
	class ApartmentComplex :
		public Environment
	{
	public:
		ApartmentComplex(std::string & desc);
		~ApartmentComplex();
	};
}
