#pragma once
#include <string>
#include <vector>
#include <atomic>
#include <unordered_map>
#include <iostream>
#include "Item.h"

namespace AdventureTime {
	class Environment {
	private: 
		int id;
		std::string description;
		std::unordered_map<std::string, int> directions; 
		std::vector<Item> items; 
	protected:
		static std::atomic<int> s_id;
	public:
		Environment();
		Environment(std::string & description);
		virtual ~Environment();
		virtual std::string getDescription() const;
		void removeItem(Item item);
		void addItem(Item item);
		int getID() const;
		void addDirection(std::string s, int ID);
		void printDirections();
		int getNextRoom(const std::string direction);
	};
}
