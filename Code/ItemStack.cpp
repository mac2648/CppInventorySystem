#include "ItemStack.h"

#include <iostream>

ItemStack::ItemStack(const Item& InItem, int InQuantity)
	: StackedItem(InItem) , Quantity(InQuantity)
{
	if (StackedItem.GetMaxStackSize() < Quantity)
	{
		Quantity = StackedItem.GetMaxStackSize();
	}

	if (Quantity == 0)
	{
		std::cout << "created a stack with 0 items, this stack is empty\n";
	}
}

bool ItemStack::CanAdd(int Amount) const
{
	return StackedItem.GetMaxStackSize() >= (Quantity + Amount);
}

int ItemStack::Add(int Amount)
{
	Quantity += Amount;

	if (Quantity > StackedItem.GetMaxStackSize())
	{
		int Leftover = Quantity - StackedItem.GetMaxStackSize();
		Quantity -= Leftover;
		return Leftover;
	}
	else
	{
		return 0;
	}
}

int ItemStack::Add(int Amount, const Item& NewItem)
{
	if (IsEmpty())
	{
		StackedItem = NewItem;
		Quantity = 0;
		return Add(Amount);
	}
	else
	{
		return Amount;
	}
}

int ItemStack::Remove(int Amount)
{
	Quantity -= Amount;

	if (Quantity < 0)
	{
		int Leftover = -Quantity;
		Quantity = 0;
		StackedItem = Item::NoItem();
		return Leftover;
	}
	else
	{
		return 0;
	}
}

bool ItemStack::IsFull() const
{
	return Quantity == StackedItem.GetMaxStackSize();
}

bool ItemStack::IsEmpty() const
{
	//in case Quantity is not 0 but item is NoItem the stack is still considered empty
	return Quantity == 0 || StackedItem == Item::NoItem();
}