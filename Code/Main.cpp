#include "Inventory.h"
#include "Equipment.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Inventory TestInventory(20);

	TestInventory.AddItem(HealthPotion, 55);
	TestInventory.AddItem(IronSword, 2);

	TestInventory.PrintInventory();

	cout << "\n\n";

	TestInventory.RemoveItem(HealthPotion, 41);
	TestInventory.AddItem(IronHelmet, 1);

	TestInventory.PrintInventory();

	Equipment TestEquipment;

	std::optional<ItemStack> Gear = TestInventory.RetriveItem("Iron Sword");
	if (Gear)
	{
		TestEquipment.Equip(Gear.value());
	}

	TestInventory.AddItem(BronzeSword, 1);

	cout << "\nPart 2 -----------------------\n\n";
	TestEquipment.PrintEquipment();
	TestInventory.PrintInventory();

	Gear = TestInventory.RetriveItem(BronzeSword);
	if (Gear)
	{
		Gear = TestEquipment.Equip(Gear.value());
		if (Gear)
		{
			TestInventory.AddStack(Gear.value());
		}
	}

	cout << "Part 3 -----------------------\n\n";
	TestEquipment.PrintEquipment();
	TestInventory.PrintInventory();

	return 0;
}