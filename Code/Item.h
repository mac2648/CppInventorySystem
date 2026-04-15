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

EquipmentSlot operator++(EquipmentSlot& Slot, int);
EquipmentSlot& operator++(EquipmentSlot& Slot);

constexpr const char* ToString(EquipmentSlot Slot)
{
    switch (Slot)
    {
    case EquipmentSlot::Head:   return "Head";
    case EquipmentSlot::Chest:  return "Chest";
    case EquipmentSlot::Legs:   return "Legs";
    case EquipmentSlot::Weapon: return "Weapon";
    case EquipmentSlot::Shield: return "Shield";
    }

    return "Unknown";
}

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

    bool operator==(const Item& Other) const;

private:

    std::string Name;

    ItemType Type;

    int MaxStackSize;

    std::optional<EquipmentSlot> EquipSlot;

public:
    //public static value used to identify an item as empty
    static Item NoItem;
};


// This is not an implementation for an Item list, it's for testing purposes to reduce the typing required to create Items.
static Item HealthPotion("Health Potion", ItemType::Consumable, 20, std::nullopt);
static Item ManaPotion("Mana Potion", ItemType::Consumable, 20, std::nullopt);
static Item IronSword("Iron Sword", ItemType::Equipment, 1, EquipmentSlot::Weapon);
static Item BronzeSword("Bronze Sword", ItemType::Equipment, 1, EquipmentSlot::Weapon);
static Item IronHelmet("Iron Helmet", ItemType::Equipment, 1, EquipmentSlot::Head);