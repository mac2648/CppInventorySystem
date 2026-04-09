#pragma once

#include <string>
#include <optional>

enum class ItemType : uint8_t
{
    Consumable,
    Equipment,
    Material
};

enum class EquipmentSlot : uint8_t
{
    Head,
    Chest,
    Legs,
    Weapon,
    Shield
};

class Item
{
public:
    Item(std::string InName, ItemType InType, int InMaxStackSize, std::optional<EquipmentSlot> InEquipSlot);

    inline const std::string& GetName() const { return Name; }

    inline ItemType GetType() const { return Type; }

    inline int GetMaxStackSize() const { return MaxStackSize; }

    //this is redundant since std::optional can be implicitly converted to bool. But for readability reasons I will keep it.
    inline bool IsEquippable() const { return EquipSlot.has_value(); }

    inline std::optional<EquipmentSlot> GetEquipSlot() const { return EquipSlot; }

private:

    std::string Name;

    ItemType Type;

    int MaxStackSize;

    std::optional<EquipmentSlot> EquipSlot;
};


// This is not an implementation for an Item list, it's for testing purposes to reduce the typing required to create Items.

static Item HealthPotion("Health Potion", ItemType::Consumable, 20, std::nullopt);
static Item ManaPotion("Mana Potion", ItemType::Consumable, 20, std::nullopt);
static Item IronSword("Iron Sword", ItemType::Equipment, 1, EquipmentSlot::Weapon);
static Item IronHelmet("Iron Helmet", ItemType::Equipment, 1, EquipmentSlot::Head);