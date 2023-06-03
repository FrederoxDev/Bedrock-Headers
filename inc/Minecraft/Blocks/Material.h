#pragma once

#include <vector>
#include <memory>

#include "Minecraft/Util/Color.h"

enum class MaterialType : unsigned int {
    Air,
    Dirt,
    Wood,
    Stone,
    Metal,
    Water,
    Lava,
    Leaves,
    Plant,
    ReplaceablePlant,
    Sponge,
    Cloth,
    Bed,
    Fire,
    Sand,
    Decoration,
    Glass,
    Explosive,
    Ice,
    PackedIce,
    TopSnow,
    Snow,
    Cactus,
    Clay,
    Vegetable,
    Portal,
    Cake,
    Web,
    RedstoneWire,
    Carpet,
    BuildableGlass,
    Slime,
    Piston,
    Allow,
    Deny,
    Netherwart,
    StoneDecoration,
    Bubble,
    Egg,
    Barrier,
    DecorationFlammable,
    SurfaceTypeTotal,
    Any
};

class Material {
public:
    enum class Settings : int {
        Normal,
        Gas,
        Liquid,
        Decoration,
        Portal
    };
private:
    static bool mInitialized;
    MaterialType mType;
    bool mFlammable;
    bool mNeverBuildable;
    bool mAlwaysDestroyable;
    bool mReplaceable;
    bool mLiquid;
    float mTranslucency;
    bool mBlocksMotion;
    bool mBlocksPrecipitation;
    bool mSolid;
    bool mSuperHot;
    Color mMaterialColor;

public:
    bool isType(MaterialType surface) const {
        if (surface != MaterialType::Any)
            return mType == surface;
        return true;
    }
    float getTranslucency() const {
        return mTranslucency;
    }
    bool isSolid() const {
        return mSolid;
    }
    MaterialType getType() const {
        return mType;
    }
    static const Material& getMaterial(MaterialType);
};