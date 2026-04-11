#include "ItemStack.h"

#include <iostream>
#include <algorithm>
#include <cassert>

ItemStack::ItemStack(const Item& InItem, int InQuantity)
	: StackedItem(InItem) , Quantity(std::clamp(InQuantity, 0, InItem.GetMaxStackSize()))
{
}

bool ItemStack::CanAdd(int Amount) const
{
	assert(Amount >= 0);

	return StackedItem.has_value() && StackedItem->GetMaxStackSize() >= (Quantity + Amount);
}

int ItemStack::Add(int Amount)
{
	assert(Amount >= 0);

	if (!StackedItem.has_value())
	{
		return Amount;
	}

	Quantity += Amount;

	if (Quantity > StackedItem->GetMaxStackSize())
	{
		int SpaceLeft = StackedItem->GetMaxStackSize() - Quantity;
		int Added = std::min(Amount, SpaceLeft);
		Quantity += Added;
		return Amount - Added;
	}
	else
	{
		return 0;
	}
}

int ItemStack::Add(int Amount, const Item& NewItem)
{
	assert(Amount >= 0);

	if (!IsEmpty())
	{
		return Amount;
	}

	StackedItem = NewItem;
	Quantity = 0;
	return Add(Amount);
}

int ItemStack::Remove(int Amount)
{
	assert(Amount >= 0);

	int Removed = std::min(Amount, Quantity);
	Quantity -= Removed;

	if (Quantity == 0)
	{
		StackedItem.reset();
	}
	return Amount - Removed;
}

bool ItemStack::IsFull() const
{
	return StackedItem.has_value() && Quantity == StackedItem->GetMaxStackSize();
}

bool ItemStack::IsEmpty() const
{
	//in case Quantity is not 0 but item is NoItem the stack is still considered empty
	return Quantity == 0 || !StackedItem.has_value();
}