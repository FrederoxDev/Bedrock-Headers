// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
#include <vector>
#include <chrono>
#include "Minecraft/Memory/SharedPtr.h"
class ReadOnlyBinaryStream;
class ItemStackBase;
class ItemDescriptor;
class BinaryStream;
class BlockSource;
class BlockLegacy;
class IDataOutput;
class IDataInput;
class ItemEnchants;
class Actor;
class Block;
class BlockActor;
class CompoundTag;
class ItemInstance;

class Tick { uint64_t tickID; };

namespace Json {
	class Value;
};

class ItemStackBase {
protected:
	WeakPtr<Item> mItem;
public:
	std::unique_ptr<CompoundTag> mUserData;
protected:
	const Block* mBlock;
	short mAuxValue;
	unsigned char mCount;
	bool mValid;
	std::chrono::steady_clock::time_point mPickupTime;
	bool mShowPickUp;
	std::vector<const BlockLegacy*> mCanPlaceOn;
	size_t mCanPlaceOnHash;
	std::vector<const BlockLegacy*> mCanDestroy;
	size_t mCanDestroyHash;
	Tick mBlockingTick;
private:
	std::unique_ptr<ItemInstance> mChargedItem;

protected:
	virtual ~ItemStackBase();
	virtual void reinit(const BlockLegacy&, int) = 0;
	virtual void reinit(const Item&, int, int) = 0;

// Begin Non-Virtual Functions
public:
	const Item* getItem() const;
	bool sameItem(int, int) const;
	void _write(BinaryStream&) const;
	void _read(ReadOnlyBinaryStream&);
	ItemDescriptor getDescriptor() const;
	bool isNull() const;
	void setNull();
	void set(int);
	bool hasSameUserData(const ItemStackBase&) const;
	bool hasSameAuxValue(const ItemStackBase&) const;
	void setUserData(std::unique_ptr<CompoundTag>);
	std::unique_ptr<CompoundTag> getNetworkUserData() const;
	void addCustomUserData(BlockActor&, BlockSource&);
	bool isEnchanted() const;
	ItemEnchants getEnchantsFromUserData() const;
	void saveEnchantsToUserData(const ItemEnchants&);
	unsigned char getMaxStackSize() const;
	bool isStackable(const ItemStackBase&) const;
	bool isStackedByData() const;
	bool isDamaged() const;
	short getAuxValue() const;
	void hurtAndBreak(int, Actor*);
	bool sameItemAndAux(const ItemStackBase&) const;
	std::string getDescriptionId() const;
	std::string getName() const;
	std::string getRawNameId() const;
	short getId() const;
	int getIdAux() const;
	bool isBlock() const;
	std::string toString() const;
	bool matches(const ItemStackBase&) const;
	bool matchesItem(const ItemStackBase&) const;
	std::unique_ptr<CompoundTag,std::default_delete< CompoundTag>> save() const;
	bool isHorseArmorItem() const;
	bool isWearableItem() const;
	bool isPotionItem() const;
	std::string getCustomName() const;
	std::string getHoverName() const;
	void setCustomName(const std::string&);
	void setCustomLore(const std::vector<std::string,std::allocator<std::string>>&);
	bool hasCustomHoverName() const;
	void setRepairCost(int);
	void clearChargedItem();
	void setChargedItem(const ItemInstance&, bool);
	bool addComponents(const Json::Value&, std::string&);
	bool hasComponent(const std::string&) const;
	bool updateComponent(const std::string&, const Json::Value&);
	void serializeComponents(IDataOutput&) const;
	void deserializeComponents(IDataInput&);
	bool isExperimental() const;

	void setMaxDamage(short newDamage) {
		if (mItem != nullptr) {
			getItem()->setDamageValue(*this, newDamage);
		}
	}

private:
	void _setChargedItem(const ItemInstance&);
	void _makeChargedItemFromUserData();
	void _loadItem(const CompoundTag&);
	void _updateCompareHashes();
	void _loadComponents(const CompoundTag&);
protected:
	ItemStackBase();
	ItemStackBase(const BlockLegacy&, int);
	ItemStackBase(const Block&, int, const CompoundTag*);
	ItemStackBase(const Item&);
	ItemStackBase(const Item&, int);
	ItemStackBase(const Item&, int, int);
	ItemStackBase(const Item&, int, int, const CompoundTag*);
	ItemStackBase(const ItemStackBase&);
	bool _setItem(int);
	void init(const BlockLegacy&, int);
	void init(const Item&, int, int, const CompoundTag*);
	void init(int, int, int);
	std::string _getHoverFormattingPrefix() const;

// Begin Variables
// public: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_DISPLAY;
// public: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_DISPLAY_NAME;
// public: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_LORE;
// public: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_REPAIR_COST;
// public: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_CAN_PLACE_ON;
// public: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_CAN_DESTROY;
// protected: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_STORE_CAN_PLACE_ON;
// protected: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_STORE_CAN_DESTROY;
// protected: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_CHARGED_ITEM;
// public: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ItemStackBase::TAG_ENCHANTS;
};