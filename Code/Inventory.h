#pragma once

#include "ItemStack.h"
#include <vector>

class Inventory
{
public:
    Inventory(size_t InCapacity);

    int AddItem(const Item& ItemToAdd, int Quantity);

    int AddStack(const ItemStack& StackToAdd);

    int RemoveItem(const Item& ItemToRemove, int Quantity);

    void PrintInventory() const;

    inline size_t GetCapacity() const { return Slots.size(); }

    //finds and removes the Item from the inventory. returns the removed Item. Will retrive the first item match
    std::optional<ItemStack> RetriveItem(const Item& Item);
    std::optional<ItemStack> RetriveItem(std::string ItemName);
    std::optional<ItemStack> RetriveItem(int ItemIndex);


private:

    int AddToExistingStacks(const Item& AddItem, int Quantity);

    int AddToEmptySlots(const Item& AddItem, int Quantity);

private:

    std::vector<std::optional<ItemStack>> Slots;
};