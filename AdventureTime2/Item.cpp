#include "Item.h"

std::atomic<int> AdventureTime::Item::s_id;

AdventureTime::Item::Item(int quality, int price, std::string description) :
id(++s_id),
quality(quality),
price(price),
description(description)
{
}

AdventureTime::Item::~Item()
{

}

void AdventureTime::Item::use()
{

}
