#include "Item.h"
#include <iostream>

using std::cout;

int main()
{
	Item Items[4]{ HealthPotion, ManaPotion, IronSword, IronHelmet };

	for (Item& CurrItem : Items)
	{
		cout << "Name: " << CurrItem.GetName() << " Item Type: " << int(CurrItem.GetType()) << " Max Stacks: " << CurrItem.GetMaxStackSize();
		if (CurrItem.IsEquippable())
		{
			cout << " Equipament Type: " << int(CurrItem.GetEquipSlot().value());
		}

		cout << std::endl;
	}

	return 0;
}