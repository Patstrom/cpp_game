#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Actor.h"

namespace AdventureTime {
	class Master : 
		public virtual Actor
	{
	private:
		const int WALK = 0;
	public:
		Master();
		virtual ~Master() = default;
		virtual void act();
	};
}
