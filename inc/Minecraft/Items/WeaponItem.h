// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
class Mob;
class Player;
class ItemStackBase;
class Block;
class Level;
class ItemStack;
class ItemInstance;
// struct std::string;


class WeaponItem {
public:
	// ~WeaponItem
	virtual bool canDestroySpecial(const Block&) const;
	virtual int getAttackDamage() const;
	virtual bool isHandEquipped() const;
	virtual bool canDestroyInCreative() const;
	virtual void appendFormattedHovertext(const ItemStackBase&, Level&, std::string&, bool) const;
	virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&) const;
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual ItemStack& use(ItemStack&, Player&) const;
	virtual float getDestroySpeed(const ItemInstance&, const Block&) const;
	virtual void hurtEnemy(ItemStack&, Mob*, Mob*) const;

// Begin Non-Virtual Functions

// Begin Variables
};