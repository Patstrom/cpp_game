#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Environment.h"

namespace AdventureTime {
	class Player
	{
	private:
		std::string playerName;
		std::vector<Item> Inventory;
		int currentRoom;
	public:
		Player();
		~Player();
		void setPlayerName(const std::string s);
		void setCurrentRoom(int e);
		int getCurrentRoom();
		void addItem(Item item);
		void removeItem(Item item);
	};
}
