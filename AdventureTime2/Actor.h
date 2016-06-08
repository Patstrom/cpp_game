#pragma once
#include <string>
#include <vector>
#include <memory>
#include <atomic>
#include <iostream>
#include "Environment.h"

namespace AdventureTime {
	class Actor :
		public std::enable_shared_from_this<Actor>
	{
	protected:
		std::string name;
		bool finished;
		std::shared_ptr<Environment> currentRoom;
	public:
		Actor(std::string name);
		virtual ~Actor() = default;
		virtual void act() = 0;
		bool isFinished() const;
		void setCurrentRoom(std::shared_ptr<Environment> e);
		std::string getName() const;
	};
}