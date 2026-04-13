#include "Inventory.h"

#include <cassert>
#include <iostream>

Inventory::Inventory(short Capacity)
{
	Slots.resize(Capacity);
}

int Inventory::AddItem(const Item& ItemToAdd, int Quantity)
{
	assert(Quantity >= 0);

	int Leftover = AddToExistingStacks(ItemToAdd, Quantity);

	if (Leftover > 0)
	{
		Leftover = AddToEmptySlots(ItemToAdd, Leftover);
	}

	return Leftover;
}

int Inventory::RemoveItem(const Item& ItemToRemove, int Quantity)
{
	assert(Quantity >= 0);

	int RemainingAmount = Quantity;
	for (std::optional<ItemStack>& Slot : Slots)
	{
		if (Slot.has_value() && Slot->GetItem() == ItemToRemove)
		{
			RemainingAmount = Slot->Remove(RemainingAmount);

			if (RemainingAmount == 0)
			{
				break;
			}
		}
	}

	return RemainingAmount;
}

void Inventory::PrintInventory() const
{
	for (const std::optional<ItemStack>& Slot : Slots)
	{
		if (Slot.has_value() && !Slot->IsEmpty())
		{
			std::cout << "Item: " << Slot->GetItem().GetName() << " Quantity: " << Slot->GetQuantity() << std::endl;
		}
	}
}

int Inventory::AddToExistingStacks(const Item& ItemToAdd, int Quantity)
{
	assert(Quantity >= 0);

	int RemainingAmount = Quantity;
	for (std::optional<ItemStack>& Slot : Slots)
	{
		if (Slot.has_value() && !Slot->IsFull() && Slot->GetItem() == ItemToAdd)
		{
			RemainingAmount = Slot->Add(RemainingAmount);

			if (RemainingAmount == 0)
			{
				break;
			}
		}
	}

	return RemainingAmount;
}

int Inventory::AddToEmptySlots(const Item& ItemToAdd, int Quantity)
{
	assert(Quantity >= 0);

	int RemainingAmount = Quantity;
	for (std::optional<ItemStack>& Slot : Slots)
	{
		if (!Slot.has_value())
		{
			Slot.emplace(ItemToAdd, 0);
			RemainingAmount = Slot->Add(RemainingAmount);

			if (RemainingAmount == 0)
			{
				break;
			}
		}
	}

	return RemainingAmount;
}