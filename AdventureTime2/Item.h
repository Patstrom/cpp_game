#pragma once
#include <string>
#include <vector>
#include <atomic>

namespace AdventureTime {
	class Item {
	private:
		const int id;
		int quality;
		int price;
		std::string description;
	public:
		Item(int quality, int price, std::string description);
		~Item();
		std::string getDescription() const;
		virtual void use();
	protected:
		static std::atomic<int> s_id;
	};
}
