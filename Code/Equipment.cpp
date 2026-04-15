#include "Equipment.h"

#include <iostream>

std::optional<ItemStack> Equipment::Equip(const ItemStack& Stack)
{
	if (Stack.GetItem() == Item::NoItem)
	{
		return std::nullopt;
	}

	if (!Stack.GetItem().IsEquippable())
	{
		return Stack;
	}

	EquipmentSlot SlotToEquip = Stack.GetItem().GetEquipSlot().value();

	std::optional<ItemStack> CurrentEquipedItem;

	if (Equipped.contains(SlotToEquip))
	{
		CurrentEquipedItem = Equipped[SlotToEquip];
	}

	Equipped[SlotToEquip] = Stack;

	return CurrentEquipedItem;
}

std::optional<ItemStack> Equipment::Unequip(EquipmentSlot Slot)
{
	if (!Equipped.contains(Slot))
	{
		return std::nullopt;
	}

	ItemStack EquippedItem = Equipped[Slot];
	Equipped.erase(Slot);

	return EquippedItem;
}

const ItemStack* Equipment::GetEquippedItem(EquipmentSlot Slot) const
{
	if (!Equipped.contains(Slot))
	{
		return nullptr;
	}

	return &Equipped.at(Slot);
}

void Equipment::PrintEquipment() const
{
	std::cout << "Equipment\n";
	for (EquipmentSlot Slot = EquipmentSlot::Head; Slot <= EquipmentSlot::Shield; Slot++)
	{
		if (!Equipped.contains(Slot))
		{
			continue;
		}

		std::cout << ToString(Slot) << ": " << Equipped.at(Slot).GetItem().GetName() << std::endl;
	}
}