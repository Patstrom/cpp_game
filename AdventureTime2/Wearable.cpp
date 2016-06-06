#include "stdafx.h"
#include "Wearable.h"

AdventureTime::Wearable::Wearable(std::string && description) :
Item(std::string("wearable"),std::move(description))
{
}