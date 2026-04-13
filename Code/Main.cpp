#include "Inventory.h"
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
	TestInventory.RemoveItem(IronHelmet, 1);

	TestInventory.PrintInventory();

	return 0;
}