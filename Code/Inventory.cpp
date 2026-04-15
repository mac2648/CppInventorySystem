#include "Inventory.h"

#include <cassert>
#include <iostream>

Inventory::Inventory(size_t InCapacity)
{
	assert(InCapacity > 0);
	Slots.resize(InCapacity);
}

int Inventory::AddItem(const Item& ItemToAdd, int Quantity)
{
	assert(Quantity >= 0);

	int RemainingAmount = AddToExistingStacks(ItemToAdd, Quantity);

	if (RemainingAmount > 0)
	{
		RemainingAmount = AddToEmptySlots(ItemToAdd, RemainingAmount);
	}

	return RemainingAmount;
}

int Inventory::RemoveItem(const Item& ItemToRemove, int Quantity)
{
	assert(Quantity >= 0);

	int RemainingAmount = Quantity;
	for (std::optional<ItemStack>& Slot : Slots)
	{
		if (!Slot.has_value())
		{
			continue;
		}

		if (!(Slot->GetItem() == ItemToRemove))
		{
			continue;
		}

		RemainingAmount = Slot->Remove(RemainingAmount);

		if (RemainingAmount == 0)
		{
			break;
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