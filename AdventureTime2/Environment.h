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
		const int id;
		std::unordered_map<std::string, int> directions; 
		std::vector<Item> items; 
	protected:
		static std::atomic<int> s_id;
		std::string description;
	public:
		Environment(std::string & description);
		virtual ~Environment() = default;
		virtual std::string getDescription() const = 0;
		virtual const bool isIndoors() const = 0;
		void removeItem(Item item);
		void addItem(Item item);
		int getID() const;
		void addDirection(std::string s, int ID);
		void printDirections();
		int getNextRoom(const std::string direction);
	};
}
