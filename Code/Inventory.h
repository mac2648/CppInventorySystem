#pragma once

#include "ItemStack.h"
#include <vector>

class Inventory
{
public:
    Inventory(short InCapacity);

    int AddItem(const Item& ItemToAdd, int Quantity);

    int RemoveItem(const Item& ItemToRemove, int Quantity);

    void PrintInventory() const;

    inline int GetCapacity() const { return Slots.size(); }

private:

    int AddToExistingStacks(const Item& AddItem, int Quantity);

    int AddToEmptySlots(const Item& AddItem, int Quantity);

private:

    std::vector<std::optional<ItemStack>> Slots;
};