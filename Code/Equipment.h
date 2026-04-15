#pragma once

#include "ItemStack.h"
#include <unordered_map>

namespace std
{
    template<>
    struct hash<EquipmentSlot>
    {
        size_t operator()(const EquipmentSlot& slot) const noexcept
        {
            return static_cast<size_t>(slot);
        }
    };
}

class Equipment
{
public:

    //if fail returns the Itemstack given as input.
    //if success returns the itenm that was equiped at that slot
    std::optional<ItemStack> Equip(ItemStack& Stack);

    std::optional<ItemStack> Unequip(EquipmentSlot Slot);

    const ItemStack* GetEquippedItem(EquipmentSlot Slot) const;

    void PrintEquipment() const;

private:
    std::unordered_map<EquipmentSlot, ItemStack> Equipped;
};