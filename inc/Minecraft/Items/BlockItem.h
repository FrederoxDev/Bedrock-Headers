#pragma once

#include "Minecraft/Items/Item.h"

class BlockItem : public Item {
public:
    BlockItem(const std::string&, int);
    virtual ~BlockItem();
    virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
    virtual int getIconYOffset() const;
    virtual bool isValidAuxValue(int) const;
    virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
    virtual bool isEmissive(int) const;
    virtual bool isDestructive(int) const;
    virtual bool isExperimental(const ItemDescriptor*) const;
private:
    virtual bool _useOn(ItemStack&, Actor&, BlockPos, unsigned char, float, float, float) const;
    virtual bool _calculatePlacePos(ItemStack&, Actor&, unsigned char&, BlockPos&) const;
};