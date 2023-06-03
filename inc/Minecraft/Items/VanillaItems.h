#pragma once

class ActorInfoRegistry;
class BlockDefinitionGroup;

#include "Minecraft/Memory/SharedPtr.h"
#include "Minecraft/Items/Item.h"

class VanillaItems {
public:
	static WeakPtr<Item>& mBucket;
	static WeakPtr<Item>& mIronIngot;
	static WeakPtr<Item>& mGoldIngot;
	static WeakPtr<Item>& mShears;
	static WeakPtr<Item>& mString;
	static WeakPtr<Item>& mDiamond;
	static WeakPtr<Item>& mGlowstone;
	static WeakPtr<Item>& mRedstone;

	static void registerItems(bool);
	static void unregisterItems();
	static void initCreativeItemsCallback(ActorInfoRegistry*, BlockDefinitionGroup*, bool);
	static void initCreativeCategories();
	static void initClientData();
};