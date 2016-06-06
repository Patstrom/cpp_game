#pragma once
#include "stdafx.h"
#include "Indoors.h"

AdventureTime::Indoors::Indoors(std::string & description) : 
Environment(description)
{
}

AdventureTime::Indoors::~Indoors()
{

}

std::string AdventureTime::Indoors::getDescription() const {
	return description;
}

const bool AdventureTime::Indoors::isIndoors() const {
	return true;
}
