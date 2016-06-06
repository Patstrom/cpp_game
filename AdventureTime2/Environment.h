#pragma once
#include <string>
#include <vector>
#include <atomic>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <memory>

namespace AdventureTime {
	class Environment {
	private: 
		const int id;
		std::unordered_map<std::string, int> directions; 
		std::vector<int> items;
	protected:
		static std::atomic<int> s_id;
		std::string description;
	public:
		Environment(std::string && description);
		virtual ~Environment() = default;
		virtual std::string getDescription() const = 0;
		void removeItem(int item);
		void addItem(int item);
		int getID() const;
		void addDirection(std::string s, int ID);
		void printDirections();
		std::vector<int> getItems();
		int getNextRoom(const std::string direction);
	};
}
