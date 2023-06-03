#pragma once
#include "Minecraft/Blocks/BlockLegacy.h"
#include "Minecraft/NBT/CompoundTag.h"

typedef CompoundTag BlockSerializationId;
typedef unsigned int BlockRuntimeId;

class Block {
private:
    const DataID mData;
    WeakPtr<BlockLegacy> mLegacyBlock;
    BlockSerializationId mSerializationId;
    BlockRuntimeId mRuntimeId;
    bool mHasRuntimeId;

public:
    const BlockLegacy& getLegacyBlock() const;

    /*bool isSolid() const;
    const Block& getDefaultState() const;
    const Material& getMaterial() const;
    bool canContainLiquid() const;
    void spawnResources(BlockSource& region, const BlockPos& pos, float explosionRadius, int bonusLootLevel) const;
    void spawnResources(BlockSource& region, const BlockPos& pos, const Block& block, float explosionRadius, int bonusLootLevel) const;
    bool hasProperty(BlockProperty type) const;
    ItemInstance asItemInstance(BlockSource& region, const BlockPos& pos) const;
    ItemInstance getSilkTouchItemInstance() const;
    void playerDestroy(Player& player, const BlockPos& pos) const;
    const AABB& getVisualShape(AABB&, bool) const;
    int getColor(BlockSource&, const BlockPos&) const;
    int getColorAtPos(BlockSource&, const BlockPos&) const;
    BlockRenderLayer getRenderLayer(BlockSource&, const BlockPos&) const;
    bool isSeasonTinted(BlockSource&, const BlockPos&) const;
    bool canHaveExtraData() const
    {
        if (mLegacyBlock != nullptr)
            return mLegacyBlock->canHaveExtraData();
        else
            return false;
    };
    int getVariant() const;

    const BlockRuntimeId& getRuntimeId() const {
        return mRuntimeId;
    }

    const DataID& getDataDEPRECATED() const {
        return mData;
    }

    const Block& keepState(const ItemState& state) const {
        if (!hasState(state))
            return *this;
        int oldValue = getState<int>(state);
        return *getDefaultState().setState<int>(state, oldValue);
    }

    bool hasState(const ItemState& stateType) const {
        return mLegacyBlock->hasState(stateType);
    }

    template<typename T>
    T getState(const ItemState& stateType) const {
        return mLegacyBlock->getState<T>(stateType, mData);
    }

    template<typename T>
    const Block* setState(const ItemState& stateType, T val) const {
        return mLegacyBlock->setState<T>(stateType, val, mData);
    }*/
};