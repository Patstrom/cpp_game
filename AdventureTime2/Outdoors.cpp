//#include "stdafx.h"
#include "Outdoors.h"


AdventureTime::Outdoors::Outdoors(std::string && description, int chance_of_rain) :
Environment(std::move(description))
{
	if (chance_of_rain < 0 || chance_of_rain > 100) {
		throw std::invalid_argument("chance_of_rain not between 0 or 100");
	}
	else {
		this->chance_of_rain = chance_of_rain;
	}
}


std::string AdventureTime::Outdoors::getDescription() const {
	srand(time(NULL));
	if (std::rand() % 100 < chance_of_rain) {
		std::string temp;
		temp.append(description);
		temp.append(std::string("\nIt is raining D:"));
		return temp;
	}
	else {
		return description;
	}
}

