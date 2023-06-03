// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
class BlockLegacy;
class Item;
class Block;
class CompoundTag;

class ItemInstance {
public:
	virtual ~ItemInstance();
protected:
	virtual void reinit(const Item&, int, int);
public:
	virtual void reinit(const BlockLegacy&, int);

// Begin Non-Virtual Functions
	ItemInstance();
	ItemInstance(const BlockLegacy&, int);
	ItemInstance(const Block&, int, const CompoundTag*);
	ItemInstance(const Item&);
	ItemInstance(const Item&, int);
	ItemInstance(const Item&, int, int);
	static ItemInstance fromTag(const CompoundTag&);

// Begin Variables
// public: static class ItemInstance const ItemInstance::EMPTY_ITEM;
};