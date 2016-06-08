//#include "stdafx.h"
#include "Ball.h"


AdventureTime::Ball::Ball(std::string && description) :
Item(std::string("ball"), std::move(description))
{
}

void AdventureTime::Ball::use() {
	std::cout << "Bouncy ball. So much fun!";
}

std::string AdventureTime::Ball::getDescription() const {
	return description;
}
