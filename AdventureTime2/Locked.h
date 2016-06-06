#pragma once
namespace AdventureTime {
	class Locked 
	{
	private:
		const int itemId;
	public:
		Locked(int id);
		~Locked() = default;
		int getItemId() const;
	};
}
