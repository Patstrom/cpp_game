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
		std::vector<int> inventory;
		std::vector<int> equipped;
		int currentRoom;
	public:
		Player();
		~Player() = default;
		void setPlayerName(const std::string s);
		void setCurrentRoom(int e);
		int getCurrentRoom() const;
		void addItem(int id);
		void removeItem(int id);
		std::vector<int> getItems() const;
	};
}
