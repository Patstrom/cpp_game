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
		std::vector<std::weak_ptr<Item>> inventory;
		std::vector<std::weak_ptr<Item>> equipped;
		Parser parser;
		bool processCommand(const Command & c);
		bool goToRoom(const Command & c);
		void pickUp(const Command & c);
		bool useItem(const Command & c);
		void equipItem(const Command & c);
		void showInventory() const;
		void showEquipped() const;
		void help() const;
		void addItem(std::weak_ptr<Item> item);
		void removeItem(std::weak_ptr<Item> item);
		std::vector<std::weak_ptr<Item>> getItems() const;
		std::vector<std::weak_ptr<Item>> getEquipped() const;
		void equip(std::weak_ptr<Item> item);
		void unequip(std::weak_ptr<Item> item);
		void printLocationDetails() const;
	public:
		Player();
		virtual ~Player() = default;
		virtual void act();
	};
}
