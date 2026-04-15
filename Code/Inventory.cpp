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

int Inventory::AddStack(const ItemStack& StackToAdd)
{
	return AddItem(StackToAdd.GetItem(), StackToAdd.GetQuantity());
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

		if (Slot->GetQuantity() <= 0)
		{
			Slot.reset();
		}

		if (RemainingAmount == 0)
		{
			break;
		}
		
	}

	return RemainingAmount;
}

void Inventory::PrintInventory() const
{
	std::cout << "Inventory\n";
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

std::optional<ItemStack> Inventory::RetriveItem(const Item& Item)
{
	return RetriveItem(Item.GetName());
}

std::optional<ItemStack> Inventory::RetriveItem(std::string ItemName)
{
	for (std::optional<ItemStack>& Slot : Slots)
	{
		if (!Slot.has_value())
		{
			continue;
		}

		if (Slot->GetItem().GetName() == ItemName)
		{
			ItemStack RemovedStack = Slot.value();
			Slot.reset();
			return RemovedStack;
		}
	}

	return std::nullopt;
}

std::optional<ItemStack> Inventory::RetriveItem(int ItemIndex)
{
	if (ItemIndex >= Slots.size() || ItemIndex < 0)
	{
		return std::nullopt;
	}

	return Slots[ItemIndex];
}