#pragma once;
#include <vector>
#include <string>
#include <memory>

#include "BlockShape.h"
#include "TextureAtlasItem.h"
#include "Minecraft/Util/Color.h"
#include "Minecraft/Client/BlockGeometry.h"
#include "Minecraft/Client/BlockRenderLayer.h"

class Block;
class BlockPalette;

namespace Json {
    class Value;
};

enum class BlockSoundType : int {
    Normal,
    Gravel,
    Wood,
    Grass,
    Metal,
    Stone,
    Cloth,
    Glass,
    Sand,
    Snow,
    Ladder,
    Anvil,
    Slime,
    Silent,
    ItemFrame,
    TurtleEgg,
    Bamboo,
    BambooSapling,
    Lantern,
    Scaffolding,
    SweetBerryBush,
    Default,
    Undefined
};

struct TextureItem {
    std::string defaultName;
    std::string carriedName;
    TextureAtlasItem defaultItem;
    TextureAtlasItem carriedItem;
};

class BlockGraphics {
public:
    struct ModelItem {
        std::string name;
        const BlockGeometry::TessellatedModel* model;
        std::vector<unsigned long> textureIndices;
    };
    struct ConstructorToken {};

    static std::vector<std::unique_ptr<BlockGraphics>>* mOwnedBlocks;
    IsotropicFaceData mIsotropicFaceData;
protected:
    const Block* mBlock;
    BlockRenderLayer mRenderLayer;
    BlockShape mBlockShape;
    bool mAnimatedTexture;
    float mBrightnessGamma;
    Color mMapColor;
    bool mFancy;
    bool mAllowSame;
private:
    BlockSoundType mSoundType;
    AABB mVisualShape;
    std::vector<TextureItem> mTextureItems;
    size_t mIconTextureIndex;
    std::vector<std::vector<BlockGeometry::Model const*>> mBlockModelVariants;
    std::vector<std::vector<ModelItem>> mTessellatedModelParts;

public:
    static BlockGraphics& registerBlockGraphics(std::vector<Json::Value>&, const std::string&, BlockShape);
    static void registerLooseBlockGraphics(std::vector<Json::Value>&, const BlockPalette&);
    static const BlockGraphics* getForBlock(const Block&);

    virtual ~BlockGraphics();

    const TextureUVCoordinateSet& getTexture(size_t textureSlot, int blockVariant) const {
        return getTextureDefaultVariations(textureSlot, blockVariant).front();
    }

    const TextureUVCoordinateSet& getTexture(size_t textureSlot, const Block& block) const {
        return getTexture(textureSlot, block.getVariant());
    }

    const TextureUVCoordinateSet& getTexture(const BlockPos& pos, size_t textureSlot, int blockVariant) const;

    const TextureUVCoordinateSet& getTexture(const BlockPos& pos, size_t textureSlot, const Block& block) const {
        return getTexture(pos, textureSlot, block.getVariant());
    }

    const std::vector<TextureUVCoordinateSet>& getTextureDefaultVariations(size_t textureSlot, int blockVariant) const {
        textureSlot = std::min<size_t>(textureSlot, mTextureItems.size() - 1);
        if (blockVariant < 0 || blockVariant >= mTextureItems[textureSlot].defaultItem.uvCount())
            blockVariant = 0;
        return mTextureItems[textureSlot].defaultItem[blockVariant];
    }

    BlockShape getBlockShape() const {
        return mBlockShape;
    }
};