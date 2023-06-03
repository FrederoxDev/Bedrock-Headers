// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
#include <vector>
#include <functional>
#include "Minecraft/Memory/SharedPtr.h"
#include "Minecraft/Blocks/Material.h"
#include "Minecraft/Memory/Mutex.h"
#include "Minecraft/Util/AABB.h"
#include "Minecraft/Util/Version.h"
#include "Minecraft/Items/ItemStateInstance.h"
#include "Minecraft/Util/NewType.h"
#include "Minecraft/Blocks/BlockLegacy.h"

class BlockSource;
class SpawnConditions;
class HitResult;
class Container;
class Random;
class Vec3;
class Actor;
class BlockPos;
class Mob;
class Player;
class ItemActor;
class MobSpawnerData;
class Color;
class ItemState;
class Block;
class ItemInstance;
struct ActorBlockSyncMessage;
enum Flip;
enum CreativeItemCategory;
enum BlockProperty;
enum BlockSupportType;
enum FertilizerType;
enum BlockRenderLayer;
enum BlockActorType;
class LootComponent;

struct Brightness : public NewType<unsigned char> {
	static const Brightness MAX;
	static const Brightness MIN;
	static const Brightness INVALID;
	static Raw NUM_VALUES;
public:
	Brightness(const Raw& v) : NewType<unsigned char>(v) { }

	Brightness() : Brightness(MIN) { }

	Brightness& operator-=(const Brightness& rhs) {
		value -= rhs.value;
		return *this;
	}
	Brightness& operator+=(const Brightness& rhs) {
		value += rhs.value;
		return *this;
	}
};

class BlockLegacy {
	std::string mDescriptionId;
	std::string mRawNameId;
	std::string mNamespace;
	std::string mFullName;
	bool mFancy;
	BlockRenderLayer mRenderLayer;
	bool mRenderLayerCanRenderAsOpaque;
	BlockProperty mProperties;
	BlockActorType mBlockEntityType;
	bool mAnimatedTexture;
	float mBrightnessGamma;
	float mThickness;
	bool mCanSlide;
	bool mCanInstatick;
	bool mIsInteraction;
	float mGravity;
	const Material& mMaterial;
	Color mMapColor;
	float mFriction;
	bool mHeavy;
	float mParticleQuantityScalar;
	float mDestroySpeed;
	float mExplosionResistance;
	CreativeItemCategory mCreativeCategory;
	bool mAllowsRunes;
	bool mCanBeBrokenFromFalling;
	bool mSolid;
	bool mPushesOutItems;
	bool mIgnoreBlockForInsideCubeRenderer;
	bool mIsTrapdoor;
	bool mIsDoor;
	float mTranslucency;
	unsigned char mLightBlock;
	unsigned char mLightEmission;
	bool mShouldRandomTick;
	bool mShouldRandomTickExtraLayer;
	int mFlameOdds;
	int mBurnOdds;
	bool mIsMobPiece;
	bool mCanBeExtraBlock;
	bool mCanPropagateBrightness;
private:
	unsigned short mID;
	BaseGameVersion mMinRequiredBaseGameVersion;
	bool mExperimental;
	bool mIsVanilla;
public:
	std::unique_ptr<LootComponent> mLootComponent;
private:
	AABB mVisualShape;
	unsigned int mBitsUsed;
	unsigned int mTotalBitsUsed;
	std::array<ItemStateInstance, 105> mStates;
	std::vector<std::unique_ptr<Block>> mBlockPermutations;
	const Block* mDefaultState;
	Bedrock::Threading::SharedMutex mLegacyDataLookupTableMutex;
	std::vector<int64_t> mLegacyDataLookupTable;

public:
	virtual ~BlockLegacy();
	virtual void tick(BlockSource&, const BlockPos&, Random&) const;
	virtual const Block& getStateFromLegacyData(unsigned short) const;
	virtual const Block* getNextBlockPermutation(const Block&) const;
	virtual bool getCollisionShape(AABB&, const Block&, BlockSource&, const BlockPos&, Actor*) const;
	virtual bool isObstructingChests(BlockSource&, const BlockPos&) const;
	virtual Vec3 randomlyModifyPosition(const BlockPos&, int&) const;
	virtual Vec3 randomlyModifyPosition(const BlockPos&) const;
	virtual void addAABBs(const Block&, BlockSource&, const BlockPos&, const AABB*, std::vector<AABB>&) const;
	virtual const AABB& getAABB(BlockSource&, const BlockPos&, const Block&, AABB&, bool) const;
	virtual bool addCollisionShapes(const Block&, BlockSource&, const BlockPos&, const AABB*, std::vector<AABB>&, Actor*) const;
	virtual const AABB& getOutline(BlockSource&, const BlockPos&, AABB&) const;
	virtual bool getLiquidClipVolume(BlockSource&, const BlockPos&, AABB&) const;
	virtual void onProjectileHit(BlockSource&, const BlockPos&, const Actor&) const;
	virtual bool liquidCanFlowIntoFromDirection(unsigned char, const std::function<const Block& (const BlockPos&)>&, const BlockPos&) const;
	virtual Brightness getLightEmission(const Block&) const;
	virtual bool shouldRandomTick() const;
	virtual bool hasVariableLighting() const;
	virtual bool isStrippable(const Block&) const;
	virtual const Block& getStrippedBlock(const Block&) const;
	virtual bool canProvideSupport(const Block&, unsigned char, BlockSupportType) const;
	virtual bool canConnect(const Block&, unsigned char, const Block&) const;
	virtual void getConnectedDirections(const Block&, const BlockPos&, BlockSource&, bool&, bool&, bool&, bool&) const;
	virtual bool isCropBlock() const;
	virtual bool isStemBlock() const;
	virtual bool isContainerBlock() const;
	virtual bool isCraftingBlock() const;
	virtual bool isInteractiveBlock() const;
	virtual bool isWaterBlocking() const;
	virtual bool isHurtableBlock() const;
	virtual bool isFenceBlock() const;
	virtual bool isFenceGateBlock() const;
	virtual bool isThinFenceBlock() const;
	virtual bool isWallBlock() const;
	virtual bool isStairBlock() const;
	virtual bool isSlabBlock() const;
	virtual bool isDoorBlock() const;
	virtual bool isRailBlock() const;
	virtual bool isButtonBlock() const;
	virtual bool canHurtAndBreakItem() const;
	virtual bool isSignalSource() const;
	virtual bool canBeOriginalSurface() const;
	virtual bool isValidAuxValue(int) const;
	virtual bool canFillAtPos(BlockSource&, const BlockPos&, const Block&) const;
	virtual const Block& sanitizeFillBlock(BlockSource&, const BlockPos&, const Block&) const;
	virtual void onFillBlock(BlockSource&, const BlockPos&, const Block&) const;
	virtual int getDirectSignal(BlockSource&, const BlockPos&, int) const;
	virtual bool waterSpreadCausesSpawn() const;
	virtual bool canContainLiquid() const;
	virtual bool shouldConnectToRedstone(BlockSource&, const BlockPos&, int) const;
	virtual void handleRain(BlockSource&, const BlockPos&, float) const;
	virtual bool canBeUsedInCommands(bool, const BaseGameVersion&) const;
	virtual float getThickness() const;
	virtual float getFlexibility(BlockSource&, const BlockPos&) const;
	virtual bool checkIsPathable(Actor&, const BlockPos&, const BlockPos&) const;
	virtual bool shouldDispense(BlockSource&, Container&) const;
	virtual bool dispense(BlockSource&, Container&, int, const Vec3&, unsigned char) const;
	virtual void onPlace(BlockSource&, const BlockPos&) const;
	virtual void onRemove(BlockSource&, const BlockPos&) const;
	virtual void onExploded(BlockSource&, const BlockPos&, Actor*) const;
	virtual void onStepOn(Actor&, const BlockPos&) const;
	virtual void onFallOn(BlockSource&, const BlockPos&, Actor*, float) const;
	virtual void transformOnFall(BlockSource&, const BlockPos&, Actor*, float) const;
	virtual void onRedstoneUpdate(BlockSource&, const BlockPos&, int, bool) const;
	virtual void onMove(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual bool detachesOnPistonMove(BlockSource&, const BlockPos&) const;
	virtual void movedByPiston(BlockSource&, const BlockPos&) const;
	virtual void setupRedstoneComponent(BlockSource&, const BlockPos&) const;
	virtual BlockProperty getRedstoneProperty(BlockSource&, const BlockPos&) const;
	virtual void updateEntityAfterFallOn(Actor&) const;
	virtual bool isBounceBlock() const;
	virtual bool ignoreEntitiesOnPistonMove(const Block&) const;
	virtual bool onFertilized(BlockSource&, const BlockPos&, Actor*, FertilizerType) const;
	virtual bool mayConsumeFertilizer(BlockSource&) const;
	virtual bool mayPick() const;
	virtual bool mayPick(BlockSource&, const Block&, bool) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&, unsigned char) const;
	virtual bool mayPlace(BlockSource&, const BlockPos&) const;
	virtual bool mayPlaceOn(BlockSource&, const BlockPos&) const;
	virtual bool tryToPlace(BlockSource&, const BlockPos&, const Block&, const ActorBlockSyncMessage*) const;
	virtual bool breaksFallingBlocks(const Block&) const;
	virtual void destroy(BlockSource&, const BlockPos&, const Block&, Actor*) const;
	virtual bool playerWillDestroy(Player&, const BlockPos&, const Block&) const;
	virtual bool getIgnoresDestroyPermissions(Actor&, const BlockPos&) const;
	virtual void neighborChanged(BlockSource&, const BlockPos&, const BlockPos&) const;
	virtual bool getSecondPart(BlockSource&, const BlockPos&, BlockPos&) const;
	virtual int getResourceCount(Random&, const Block&, int) const;
	virtual ItemInstance getResourceItem(Random&, const Block&, int) const;
	virtual ItemInstance asItemInstance(BlockSource&, const BlockPos&, const Block&) const;
	virtual void spawnResources(BlockSource&, const BlockPos&, const Block&, float, int) const;
	virtual bool spawnBurnResources(BlockSource&, float, float, float) const;
	virtual float getExplosionResistance(Actor*) const;
	virtual HitResult clip(BlockSource&, const BlockPos&, const Vec3&, const Vec3&, bool) const;
	virtual bool use(Player&, const BlockPos&) const;
	virtual const Block& getPlacementBlock(Actor&, const BlockPos&, unsigned char, const Vec3&, int) const;
	virtual int calcVariant(BlockSource&, const BlockPos&) const;
	virtual bool isAttachedTo(BlockSource&, const BlockPos&, BlockPos&) const;
	virtual bool attack(Player*, const BlockPos&) const;
	virtual void handleEntityInside(BlockSource&, const BlockPos&, Actor*, Vec3&) const;
	virtual void entityInside(BlockSource&, const BlockPos&, Actor&) const;
	virtual void playerDestroy(Player&, const BlockPos&, const Block&) const;
	virtual bool canSurvive(BlockSource&, const BlockPos&) const;
	virtual int getExperienceDrop(Random&) const;
	virtual bool canBeBuiltOver(BlockSource&, const BlockPos&) const;
	virtual void triggerEvent(BlockSource&, const BlockPos&, int, int) const;
	virtual void executeEvent(BlockSource&, const BlockPos&, const Block&, const std::basic_string<char, std::char_traits<char>, std::allocator<char>>&, Actor&) const;
	virtual bool hasTag(BlockSource&, const BlockPos&, const Block&, const std::string&) const;
	virtual const MobSpawnerData* getMobToSpawn(const SpawnConditions&, BlockSource&) const;
	virtual Color getMapColor(BlockSource&, const BlockPos&) const;
	virtual Color getMapColor() const;
	virtual bool shouldStopFalling(Actor&) const;
	virtual bool pushesUpFallingBlocks() const;
	virtual float calcGroundFriction(Mob&, const BlockPos&) const;
	virtual bool canHaveExtraData() const;
	virtual bool hasComparatorSignal() const;
	virtual int getComparatorSignal(BlockSource&, const BlockPos&, const Block&, unsigned char) const;
	virtual bool canSlide(BlockSource&, const BlockPos&) const;
	virtual int getIconYOffset() const;
	virtual BlockRenderLayer getRenderLayer() const;
	virtual std::string buildDescriptionId(const Block&) const;
	virtual bool isAuxValueRelevantForPicking() const;
	virtual int getColor(const Block&) const;
	virtual int getColorAtPos(BlockSource&, const BlockPos&) const;
	virtual int getColor(BlockSource&, const BlockPos&, const Block&) const;
	virtual int getColorForParticle(BlockSource&, const BlockPos&, const Block&) const;
	virtual bool isSeasonTinted(const Block&, BlockSource&, const BlockPos&) const;
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual BlockRenderLayer getRenderLayer(const Block&, BlockSource&, const BlockPos&) const;
	virtual int getExtraRenderLayers() const;
	virtual float getShadeBrightness() const;
	virtual const AABB& getVisualShapeInWorld(const Block&, BlockSource&, const BlockPos&, AABB&, bool) const;
	virtual const AABB& getVisualShape(const Block&, AABB&, bool) const;
	virtual const AABB& getUIShape(const Block&, AABB&) const;
	virtual int telemetryVariant(BlockSource&, const BlockPos&) const;
	virtual int getVariant(const Block&) const;
	virtual bool canSpawnOn() const;
	virtual unsigned char getMappedFace(unsigned char, const Block&) const;
	virtual Flip getFaceFlip(unsigned char, const Block&) const;
	virtual void animateTick(BlockSource&, const BlockPos&, Random&) const;
	virtual BlockLegacy& init();
	virtual BlockLegacy& setLightBlock(Brightness);
	virtual BlockLegacy& setLightEmission(float);
	virtual BlockLegacy& setExplodeable(float);
	virtual BlockLegacy& setDestroyTime(float);
	virtual BlockLegacy& setFriction(float);
	virtual BlockLegacy& addProperty(BlockProperty);
	virtual BlockLegacy& addState(const ItemState&);
	virtual BlockLegacy& addState(const ItemState&, size_t);
	virtual BlockLegacy& setAllowsRunes(bool);
	virtual BlockLegacy& setMapColor(const Color&);
	virtual bool canBeSilkTouched() const;
	virtual ItemInstance getSilkTouchItemInstance(const Block&) const;
	virtual void setVisualShape(const AABB&);
	virtual void setVisualShape(const Vec3&, const Vec3&);
	virtual const Block* tryLegacyUpgrade(unsigned short) const;
	virtual bool dealsContactDamage(const Actor&, const Block&, bool) const;

// Begin Non-Virtual Functions
	BlockLegacy& setMinRequiredBaseGameVersion(const BaseGameVersion&);
	void createBlockPermutations(unsigned int);
	BlockLegacy(const std::string& identifier, int id, const Material& material);
	const Block* tryGetStateFromLegacyData(unsigned short) const;
	HitResult clip(BlockSource&, const BlockPos&, const Vec3&, const Vec3&, bool, const AABB&) const;
	void spawnResources(BlockSource&, const BlockPos&, float, int) const;
	ItemActor* popResource(BlockSource&, const BlockPos&, const ItemInstance&) const;
	bool addAABB(const AABB&, const AABB*, std::vector<AABB,std::allocator<AABB> >&) const;
	BlockLegacy& setNameId(const std::string&);
	std::string buildDescriptionName(const Block&) const;
	BlockLegacy& addBlockProperty(BlockProperty);
	BlockLegacy& setExperimental();
	BlockLegacy& setCanBeExtraBlock(bool);
	BlockLegacy& setCategory(CreativeItemCategory);
	const Block& getDefaultState() const;
	short getBlockItemId() const;
	void forEachBlockPermutation(class std::function<bool(const Block&)>) const;
	void forEachItemStateInstance(class std::function<bool(const ItemStateInstance&)>) const;
	void getDebugText(std::vector<std::string,std::allocator<std::string>>&, const BlockPos&) const;
	static unsigned char getPlacementFacingAll(Actor&, const BlockPos&, float);
	static unsigned char getPlacementFacingAllExceptAxisY(Actor&, const BlockPos&, float);
	WeakPtr<BlockLegacy> createWeakPtr();

	const std::string& getDescriptionId() const {
		return mDescriptionId;
	}

	inline const std::string& getRawNameId() const {
		return mRawNameId;
	}

// Begin Variables
// public: static float const BlockLegacy::SIZE_OFFSET;
// public: static class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const BlockLegacy::BLOCK_DESCRIPTION_PREFIX;
};