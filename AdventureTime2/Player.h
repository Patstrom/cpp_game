#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Item.h"
#include "Parser.h"
#include "Actor.h"

namespace AdventureTime {
	class Player : 
		public virtual Actor
	{
	private:
		std::string playerName;
		std::vector<std::shared_ptr<Item>> inventory;
		std::vector<std::shared_ptr<Item>> equipped;
		Parser parser;
		bool processCommand(const Command & c);
		bool goToRoom(const Command & c);
		void pickUp(const Command & c);
		void useItem(const Command & c);
		void equipItem(const Command & c);
		void showInventory() const;
		void showEquipped() const;
		void help() const;
		void setPlayerName(const std::string s);
		void addItem(std::shared_ptr<Item> item);
		void removeItem(std::shared_ptr<Item> item);
		std::vector<std::shared_ptr<Item>> getItems() const;
		std::vector<std::shared_ptr<Item>> getEquipped() const;
		void equip(std::shared_ptr<Item> item);
		void unequip(std::shared_ptr<Item> item);
		void printLocationDetails() const;
	public:
		Player();
		~Player() = default;
		virtual void act();
	};
}
