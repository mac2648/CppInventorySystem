#include "Equipment.h"

std::optional<ItemStack> Equipment::Equip(ItemStack& Stack)
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

}