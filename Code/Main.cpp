#include "ItemStack.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	ItemStack Stacks[4]{ {HealthPotion, 30}, {ManaPotion, 5}, {IronHelmet, 2}, {IronSword, 0} };

	for (const ItemStack& Stack : Stacks)
	{
		if (!Stack.IsEmpty())
		{
			cout << "Item: " << Stack.GetItem().GetName() << " Quantity: " << Stack.GetQuantity() << endl;
		}
	}

	cout << endl;

	cout << "removing Items from HealthPotion return Value:" << Stacks[0].Remove(30) << endl;
	cout << "Adding Items to ManaPotion return Value:" << Stacks[1].Add(22) << endl;
	Stacks[2].Remove(0);
	Stacks[3].Add(8, HealthPotion);

	cout << endl;

	for (const ItemStack& Stack : Stacks)
	{
		if (!Stack.IsEmpty())
		{
			cout << "Item: " << Stack.GetItem().GetName() << " Quantity: " << Stack.GetQuantity() << endl;
		}
	}

	return 0;
}