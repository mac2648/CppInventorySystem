#include "Item.h"

Item Item::NoItem("", ItemType::Consumable, 0, std::nullopt); 

Item::Item(std::string InName, ItemType InType, int InMaxStackSize, std::optional<EquipmentSlot> InEquipSlot)
	: Name(std::move(InName)), Type(InType), MaxStackSize(InMaxStackSize), EquipSlot(InEquipSlot)
{
	if (Type == ItemType::Equipment)
	{
		MaxStackSize = 1;
	}
}

bool Item::operator==(const Item& Other) const
{
	return Name == Other.Name && Type == Other.Type && MaxStackSize == Other.MaxStackSize;
}