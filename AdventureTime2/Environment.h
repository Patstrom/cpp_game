#pragma once
#include <string>
#include <vector>
#include <atomic>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <memory>
#include "Item.h"

namespace AdventureTime {
	class Actor; // forward decleration
	class Environment {
	private: 
		const int id;
		std::unordered_map<std::string, std::shared_ptr<Environment>> directions; 
		std::vector<std::shared_ptr<Item>> items;
		std::vector<std::shared_ptr<Actor>> actors;
	protected:
		static std::atomic<int> s_id;
		std::string description;
	public:
		Environment(std::string && description);
		virtual ~Environment() = default;
		virtual std::string getDescription() const = 0;
		void removeItem(std::shared_ptr<Item> item);
		void addItem(std::shared_ptr<Item> item);
		int getID() const;
		void addDirection(std::string s, std::shared_ptr<Environment> environment);
		void printDirections();
		std::vector<std::shared_ptr<Item>> getItems();
		std::shared_ptr<Environment> getNextRoom(const std::string direction);
		bool hasDirection(const std::string direction) const;
		std::vector<std::shared_ptr<Environment>> getNeighbors();
		void addActor(std::shared_ptr<Actor> actor);
		std::vector<std::shared_ptr<Actor>> getActors();
		void removeActor(std::shared_ptr<Actor> actor);
	};
}
