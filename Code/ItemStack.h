#pragma once

#include "Item.h"

class ItemStack
{
public:

    ItemStack(const Item& InItem, int InQuantity);

    inline const Item& GetItem() const { return StackedItem.has_value() ? StackedItem.value() : Item::NoItem; }

    inline int GetQuantity() const { return Quantity; }

    //returns true if full Amount can be added
    bool CanAdd(int Amount) const;

    //adds to stack
    //returs remaining amount that could not be added if any.
    int Add(int Amount);
    //will add amount to stack of NewItem. Will fail if stack is not empty
    int Add(int Amount, const Item& NewItem);

    //removes from stack
    //returs the amount that could not be removed because Amount was too large.
    int Remove(int Amount);

    bool IsFull() const;
    bool IsEmpty() const;


private:

    std::optional<Item> StackedItem;

    int Quantity = 0;
};