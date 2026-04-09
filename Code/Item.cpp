#include "Item.h"

Item::Item(std::string InName, ItemType InType, int InMaxStackSize, std::optional<EquipmentSlot> InEquipSlot)
	: Name(std::move(InName)), Type(InType), MaxStackSize(InMaxStackSize), EquipSlot(InEquipSlot)
{
	if (Type == ItemType::Equipment)
	{
		MaxStackSize = 1;
	}
}