#pragma once
#include "Environment.h"

namespace AdventureTime {
	class ParkingLot :
		public Environment
	{
	public:
		ParkingLot(std::string & desc);
		~ParkingLot();
	};
}
