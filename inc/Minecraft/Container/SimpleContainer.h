// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>

#include "Minecraft/Container/Container.h"

class Player;
class ItemStack;
// struct std::string;
enum ContainerType;


class SimpleContainer : public Container {
protected:
    int mSize;
    std::vector<ItemStack, std::allocator<ItemStack> > mItems;

public:
	virtual ~SimpleContainer();
	virtual const ItemStack& getItem(int) const;
	virtual void setItem(int, const ItemStack&);
	virtual int getContainerSize() const;
	virtual int getMaxStackSize() const;
	virtual void startOpen(Player&);
	virtual void stopOpen(Player&);

// Begin Non-Virtual Functions
	SimpleContainer(const std::string&, bool, int, ContainerType);

// Begin Variables
};