#pragma once
#include <string>
#include <vector>
#include <atomic>
#include <iostream>

namespace AdventureTime {
	class Item {
	private:
		const int id;
		const std::string type;
	public:
		Item(std::string type, std::string && description);
		virtual ~Item() = default;
		virtual std::string getDescription() const;
		virtual void use() = 0;
		int getId() const;
		std::string getType() const;
	protected:
		static std::atomic<int> s_id;
		std::string description;
	};
}
