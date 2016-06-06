#pragma once
namespace AdventureTime {
	class Locked 
	{
	private:
		const int itemId;
		const bool equipped;
		bool unlocked;
	public:
		Locked(int id, bool equipped);
		~Locked() = default;
		int getItemId() const;
		bool needsEquipped() const;
		void unlock();
		bool isUnlocked() const;
	};
}
