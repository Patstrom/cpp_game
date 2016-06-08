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
		std::unordered_map<std::string, std::weak_ptr<Environment>> directions; 
		std::vector<std::weak_ptr<Item>> items;
		std::vector<std::weak_ptr<Actor>> actors;
	protected:
		static std::atomic<int> s_id;
		std::string description;
	public:
		Environment(std::string && description);
		virtual ~Environment() = default;
		virtual std::string getDescription() const = 0;
		void removeItem(std::weak_ptr<Item> item);
		void addItem(std::weak_ptr<Item> item);
		int getID() const;
		void addDirection(std::string s, std::weak_ptr<Environment> environment);
		void printDirections() const;
		std::vector<std::weak_ptr<Item>> getItems();
		std::weak_ptr<Environment> getNextRoom(const std::string direction);
		bool hasDirection(const std::string direction) const;
		std::vector<std::weak_ptr<Environment>> getNeighbors() const;
		std::vector<std::string> getDirections() const;
		void addActor(std::weak_ptr<Actor> actor);
		std::vector<std::weak_ptr<Actor>> getActors();
		void removeActor(std::weak_ptr<Actor> actor);
	};
}
