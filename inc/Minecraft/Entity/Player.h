// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
#include "Minecraft/Entity/Mob.h"

class ShieldItem;
class EnderChestContainer;
class PacketSender;
class SerializedSkin;
class BlockSource;
class DataLoadHelper;
class Item;
class Container;
class Vec2;
class Vec3;
class Actor;
class BlockPos;
class BlockActor;
class VariantParameterList;
class CompoundTag;
class ChalkboardBlockActor;
class ChunkSource;
class Packet;
class Mob;
class Agent;
class TextObjectRoot;
class ActorDamageSource;
class NetworkIdentifier;
class Block;
class EventPacket;
class Level;
class ItemStack;
class IMinecraftEventing;
class AABB;
class AnimationComponent;
struct ActorUniqueID;
struct Tick;
enum ActorEvent;
enum StructureFeatureType;
enum GameType;
enum CooldownType;
enum ItemUseMethod;
enum ActorType;
enum AbilitiesIndex;
enum PlayerUISlot;
enum CommandPermissionLevel;
enum ContainerID;
enum ArmorSlot;
enum MovementEventType;
enum ActorLocation;
enum BedSleepingResult;
class Certificate;
class IContainerManager;

namespace mce
{
	class UUID;
}

class Player : public Mob
{
private:
	static const int DATA_PLAYER_FLAGS_ID;
	static const int DATA_BED_POSITION_ID;
	static const int DATA_PLAYER_DEAD;
	static const int DATA_PLAYER_PLAYERINDEX;
	static const int PLAYER_SLEEP_FLAG;
	static const int PLAYER_DEAD_FLAG;

public:
	static const float DEFAULT_PLAYER_HEIGHT_OFFSET;
	static const float PLAYER_GLIDING_CAMERA_OFFSET;
	static const float PLAYER_SWIMMING_CAMERA_OFFSET;
	static const float PLAYER_SLEEPING_CAMERA_OFFSET;
	static const float PLAYER_SNEAK_OFFSET;
	static const float PLAYER_UP_SWIM_SPEED;
	static const float PLAYER_DOWN_SWIM_SPEED;
	static const float PLAYER_SWIM_FLY_MULTI;
	static const float PLAYER_SWIM_BREACH_ANGLE;
	static const float PLAYER_SWIM_ENTER_THRESHOLD;
	static const float DEFAULT_BB_WIDTH;
	static const float DEFAULT_BB_HEIGHT;
	static const float DISTANCE_TO_TRAVELLED_EVENT;
	static const float DISTANCE_TO_TRANSFORM_EVENT;
	static const int GLIDE_STOP_DELAY;
	static const int UNTRACKED_INTERACTION_SLOT_COUNT;
	static const Vec3 INVALID_SPAWN_POS;
	static const uint32_t SPAWN_CHUNK_RADIUS;
	static const uint32_t SPAWN_CHUNK_LARGE_JUMP;
	static const float PLAYER_ALIVE_HEIGHT;
	static const float PLAYER_ALIVE_WIDTH;
	static const float PLAYER_DEAD_HEIGHT;
	static const float PLAYER_DEAD_WIDTH;
	static const float PLAYER_SLEEPING_HEIGHT;
	static const float PLAYER_SLEEPING_WIDTH;
	static const int MAX_NAME_LENGTH;
	static const int MIN_NAME_LENGTH;
	static const int MAX_HEALTH;
	static const float DEFAULT_WALK_SPEED;
	static const float DEFAULT_FLY_SPEED;
	static const int SLEEP_DURATION;
	static const int WAKE_UP_DURATION;
	static const int ITEM_USE_DURATION;
	static const int ITEM_USE_INTERVAL_DURATION;
	static const int SLOT_HELM;
	static const int SLOT_CHEST;
	static const int SLOT_LEGGINGS;
	static const int SLOT_BOOTS;
	static const int FIXED_SPAWN_MAX_RETRIES;
	static const int ON_SCREEN_TEXTURE_ANIMATION_LENGTH;
	int mCastawayTimer;
	bool mAteKelp;
	int mLastBiome;
	std::vector<int, std::allocator<int>> mOceanBiomes;
	bool castawaySent;
	bool sailseasSent;
	static const Attribute HUNGER;
	static const Attribute SATURATION;
	static const Attribute EXHAUSTION;
	static const Attribute LEVEL;
	static const Attribute EXPERIENCE;
	Player::DimensionState mDimensionState;
	bool mServerHasMovementAuthority;
	char mUserType;
	int mScore;
	float mOBob;
	float mBob;
	bool mHandsBusy;
	std::string mName;
	BuildPlatform mBuildPlatform;
	Abilities mAbilities;
	const NetworkIdentifier mOwner;
	std::string mUniqueName;
	std::string mServerId;
	std::string mSelfSignedId;
	std::string mPlatformOfflineId;
	uint64_t mClientRandomId;
	const mce::UUID mClientUUID;
	std::unique_ptr<Certificate> mCertificate;
	std::string mPlatformId;
	ActorUniqueID mPendingRideID;
	ActorUniqueID mPendingLeftShoulderRiderID;
	ActorUniqueID mPendingRightShoulderRiderID;
	ActorUniqueID mInteractTarget;
	Vec3 mInteractTargetPos;
	bool mHasFakeInventory;
	bool mIsRegionSuspended;
	GridArea<std::shared_ptr<LevelChunk>>::AddCallback mAddCallback;
	std::unique_ptr<ChunkViewSource> mChunkSource;
	std::unique_ptr<ChunkViewSource> mSpawnChunkSource;
	std::unique_ptr<BlockSource> mOwnedBlockSource;
	BlockPos mBedPosition;
	Vec3 mTeleportDestPos;
	bool mUpdateMobs;
	Vec3 mFirstPersonLatestHandOffset;
	Vec3 mCapePosO;
	Vec3 mCapePos;
	float mPaddleForces[2];
	bool mIsPaddling[2];

protected:
	float mDistanceSinceTravelledEvent;
	float mDistanceSinceTransformEvent;
	std::shared_ptr<IContainerManager> mContainerManager;
	std::unique_ptr<PlayerInventoryProxy> mInventoryProxy;
	SerializedSkin mSkin;
	std::vector<ItemInstance, std::allocator<ItemInstance>> mCreativeItemList;
	std::array<std::vector<ItemGroup, std::allocator<ItemGroup>>, 4> mFilteredCreativeItemList;
	SubClientId mClientSubId;
	std::string mPlatformOnlineId;
	Player::SpawnPositionState mSpawnPositionState;
	Player::SpawnPositionSource mSpawnPositionSource;
	Vec3 mSpawnPositioningTestPosition;
	bool mBlockRespawnUntilClientMessage;
	uint32_t mRespawnChunkBuilderPolicyHandle;
	Player::CachedSpawnData mCachedSpawnData;
	std::unique_ptr<BlockSource> mSpawnBlockSource;
	bool mHasSeenCredits;
	Stopwatch mRespawnStopwatch_Searching;
	Vec3 mRespawnOriginalPosition;
	DimensionType mRespawnOriginalDimension;
	bool mRespawnReady;
	bool mRespawnBlocked;
	DimensionType mRespawnDimensionId;
	bool mCheckBed;
	bool mIsInitialSpawnDone;
	bool mPositionLoadedFromSave;
	int mFixStartSpawnFailures;
	ItemStack mItemInUse;
	PlayerInventoryProxy::SlotData mItemInUseSlot;
	int mItemInUseDuration;
	short mSleepCounter;
	short mPrevSleepCounter;
	bool mInteractDataDirty;
	ActorUniqueID mPreviousInteractEntity;
	int mPreviousCarriedItem;
	bool mAutoJumping;
	int mEmoteTicks;
	PacketSender &mPacketSender;
	BlockPos mBounceStartPos;
	const Block *mBounceBlock;
	float mFOVModifier;
	std::shared_ptr<HudContainerManagerModel> mHudContainerManagerModel;
	std::unique_ptr<EnderChestContainer> mEnderChestInventory;
	std::vector<ActorUniqueID, std::allocator<ActorUniqueID>> mTrackedBossIDs;
	Player::PositionMode mPositionMode;
	ActorType mLastHurtBy;
	ItemGroup mCursorSelectedItemGroup;
	PlayerUIContainer mPlayerUIContainer;
	InventoryTransactionManager mTransactionManager;
	std::unique_ptr<GameMode> mGameMode;
	PlayerRespawnRandomizer mSpawnRandomizer;
	float mVRMoveAdjAngle;

private:
	bool mUseUIAnimationComponent;
	std::shared_ptr<AnimationComponent> mUIAnimationComponent;
	PlayerListenerList mListeners;
	int mLastLevelUpTime;
	bool mPlayerLevelChanged;
	int mPreviousLevelRequirement;
	BlockPos mRespawnPosition;
	bool mIsForcedRespawnPos;
	bool mPlayerIsSleeping;
	bool mAllPlayersSleeping;
	bool mDestroyingBlock;
	Vec3 mSurvivalViewerPosition;
	std::vector<unsigned int, std::allocator<unsigned int>> mOnScreenAnimationTextures;
	int mOnScreenAnimationTicks;
	GameType mPlayerGameType;
	int mEnchantmentSeed;
	uint32_t mChunkRadius;
	int mMapIndex;
	LoopingSoundHandle mElytraLoop;
	float mUnderwaterLightLevel;
	std::vector<int, std::allocator<int>> mCooldowns;
	int64_t mStartedBlockingTimeStamp;
	int64_t mBlockedUsingShieldTimeStamp;
	int64_t mBlockedUsingDamagedShieldTimeStamp;
	bool mPrevBlockedUsingShield;
	bool mPrevBlockedUsingDamagedShield;
	bool mUsedPotion;
	int mBounceHeight;
	SkinAdjustments mSkinAdjustments;
	SerializedSkin mSerializedSkin;
	int mScanForDolphinTimer;
	bool mR5DataRecoverComplete;
	std::string mDeviceId;
	bool mFlagClientForBAIReset;
	BedHelper mBedHelper;

public:
	virtual void reloadHardcoded(Actor::InitializationMethod, const VariantParameterList &);
	virtual void initializeComponents(Actor::InitializationMethod, const VariantParameterList &);
	virtual ~Player();
	virtual void remove();
	virtual Vec3 getAttachPos(ActorLocation, float) const;
	virtual void move(const Vec3 &);
	virtual void teleportTo(const Vec3 &, bool, int, int);
	virtual std::unique_ptr<Packet, std::default_delete<Packet>> getAddPacket();
	virtual void normalTick();
	virtual void rideTick();
	virtual float getRidingHeight();
	virtual std::string getFormattedNameTag() const;
	virtual bool getAlwaysShowNameTag() const;
	virtual float getCameraOffset() const;
	virtual bool isImmobile() const;
	virtual bool isSleeping() const;
	virtual bool isShootable();
	virtual bool isBlocking() const;
	virtual bool isDamageBlocked(const ActorDamageSource &) const;
	virtual bool isCreativeModeAllowed();
	virtual bool attack(Actor &);
	virtual void adjustDamageAmount(int &) const;
	virtual bool isJumping() const;
	virtual bool isInvulnerableTo(const ActorDamageSource &) const;
	virtual void actuallyHurt(int, const ActorDamageSource *, bool);

protected:
	virtual void onBounceStarted(const BlockPos &, const Block &);

public:
	virtual void feed(int);
	virtual void handleEntityEvent(ActorEvent, int);
	virtual void awardKillScore(Actor &, int);
	virtual void setArmor(ArmorSlot, const ItemStack &);
	virtual const ItemStack &getCarriedItem() const;
	virtual void setCarriedItem(const ItemStack &);
	virtual void setOffhandSlot(const ItemStack &);
	virtual const ItemStack &getEquippedTotem() const;
	virtual bool consumeTotem();
	virtual ActorType getEntityTypeId() const;
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Actor &) const;
	virtual bool canBePulledIntoVehicle() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void startSwimming();
	virtual void stopSwimming();
	virtual CommandPermissionLevel getCommandPermissionLevel() const;
	virtual AnimationComponent &getAnimationComponent();
	virtual void useItem(ItemStack &, ItemUseMethod, bool);
	virtual float getMapDecorationRotation() const;
	virtual bool isWorldBuilder();
	virtual bool isCreative() const;
	virtual bool isAdventure() const;
	virtual bool add(ItemStack &);
	virtual bool drop(const ItemStack &, bool);
	virtual void startSpinAttack();
	virtual void stopSpinAttack();
	virtual void die(const ActorDamageSource &);

protected:
	virtual bool _hurt(const ActorDamageSource &, int, bool, bool);
	virtual void readAdditionalSaveData(const CompoundTag &, DataLoadHelper &);
	virtual void addAdditionalSaveData(CompoundTag &);

private:
	virtual void _onSizeUpdated();

public:
	virtual void setSleeping(bool);
	virtual float getSpeed() const;
	virtual void setSpeed(float);
	virtual void travel(float, float, float);
	virtual void aiStep();
	virtual int getItemUseDuration();
	virtual float getItemUseStartupProgress();
	virtual float getItemUseIntervalProgress();
	virtual const std::vector<ItemStack, std::allocator<ItemStack>> *getAllHand() const;
	virtual const std::vector<ItemStack, std::allocator<ItemStack>> *getAllEquipment() const;
	virtual void sendInventory(bool);
	virtual bool canExistWhenDisallowMob() const;
	virtual bool useNewAi() const;

private:
	virtual std::unique_ptr<BodyControl, std::default_delete<BodyControl>> initBodyControl();

public:
	virtual void jumpFromGround();

protected:
	virtual void updateAi();

public:
	virtual void dropEquipment(const ActorDamageSource &, int);
	virtual void dropEquipment();
	virtual void updateGliding();
	virtual void prepareRegion(ChunkSource &);
	virtual void destroyRegion();
	virtual void suspendRegion();
	virtual void _fireWillChangeDimension();
	virtual void _fireDimensionChanged();
	virtual void changeDimensionWithCredits(AutomaticID<Dimension, int>);
	virtual int tickWorld(const Tick &);
	// Unknown pure virtual
	virtual const std::vector<ChunkPos, std::allocator<ChunkPos>> &getTickingOffsets() const;
	virtual void moveView();
	virtual void moveSpawnView(const Vec3 &);
	virtual void setName(const std::string &);
	virtual void checkMovementStats(const Vec3 &);
	virtual StructureFeatureType getCurrentStructureFeature() const;
	virtual bool isAutoJumpEnabled() const;
	virtual void respawn();
	virtual void resetRot();
	virtual void resetPos(bool);
	virtual bool isInTrialMode();
	virtual bool hasResource(int);
	virtual void completeUsingItem();
	virtual void setPermissions(CommandPermissionLevel);
	virtual void startCrafting(const BlockPos &, bool);
	virtual void startStonecutting(const BlockPos &);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(const BlockPos &);
	virtual void openContainer(const ActorUniqueID &);
	virtual void openFurnace(const BlockPos &);
	virtual void openBlastFurnace(const BlockPos &);
	virtual void openSmoker(const BlockPos &);
	virtual void openEnchanter(const BlockPos &);
	virtual void openAnvil(const BlockPos &);
	virtual void openGrindstone(const BlockPos &);
	virtual void openBrewingStand(const BlockPos &);
	virtual void openHopper(const BlockPos &);
	virtual void openHopper(const ActorUniqueID &);
	virtual void openDispenser(const BlockPos &, bool);
	virtual void openBeacon(const BlockPos &);
	virtual void openPortfolio();
	virtual void openBook(int, bool, int, BlockActor *);
	virtual void openCommandBlock(const BlockPos &);
	virtual void openCommandBlockMinecart(const ActorUniqueID &);
	virtual void openHorseInventory(const ActorUniqueID &);
	virtual void openTrading(const ActorUniqueID &, bool);
	virtual bool canOpenContainerScreen();
	virtual void openChalkboard(ChalkboardBlockActor &, bool);
	// openNpcInteractScreen
	virtual void openInventory();
	virtual void openStructureEditor(const BlockPos &);
	virtual void openLabTable(const BlockPos &);
	virtual void openElementConstructor(const BlockPos &);
	virtual void openCompoundCreator(const BlockPos &);
	virtual void openMaterialReducer(const BlockPos &);
	virtual void openLoom(const BlockPos &);
	virtual void openStonecutter(const BlockPos &);
	virtual void openCartographyTable(const BlockPos &);
	virtual void displayChatMessage(const std::string &, const std::string &);
	virtual void displayClientMessage(const std::string &);
	virtual void displayTextObjectMessage(const TextObjectRoot &, const std::string &, const std::string &);
	// displayTextObjectWhisperMessage
	virtual void displayWhisperMessage(const std::string &, const std::string &, const std::string &, const std::string &);
	virtual BedSleepingResult startSleepInBed(const BlockPos &);
	virtual void stopSleepInBed(bool, bool);
	virtual bool canStartSleepInBed();
	virtual int getSleepTimer() const;
	virtual int getPreviousTickSleepTimer() const;
	virtual void openSign(const BlockPos &);
	virtual void playEmote(const std::string &, bool);
	virtual bool isLocalPlayer() const;
	virtual bool isHostingPlayer() const;
	virtual bool isLoading() const;
	virtual bool isPlayerInitialized() const;
	virtual void stopLoading();
	virtual void registerTrackedBoss(ActorUniqueID);
	virtual void unRegisterTrackedBoss(ActorUniqueID);
	virtual void setPlayerGameType(GameType);
	virtual void _crit(Actor &);
	virtual IMinecraftEventing *getEventing() const;
	virtual unsigned int getUserId() const;
	virtual void sendEventPacket(EventPacket &) const;
	virtual void addExperience(int);
	virtual void addLevels(int);
	// Unknown pure virtual
	// Unknown pure virtual
	virtual void inventoryChanged(Container &, int, const ItemStack &, const ItemStack &);
	// Unknown pure virtual
	virtual void deleteContainerManager();
	virtual void setFieldOfViewModifier(float);
	virtual bool isPositionRelevant(AutomaticID<Dimension, int>, const BlockPos &);
	virtual bool isEntityRelevant(const Actor &);
	// Unknown pure virtual
	virtual void onSuspension();
	virtual void onLinkedSlotsChanged();
	virtual void startCooldown(const Item *);
	virtual int getItemCooldownLeft(CooldownType) const;
	virtual bool isItemInCooldown(CooldownType) const;
	// Unknown pure virtual
	// Unknown pure virtual
	virtual void sendNetworkPacket(Packet &) const;
	// Unknown pure virtual
	// Unknown pure virtual
	// Unknown pure virtual
	// Unknown pure virtual
	virtual void reportMovementTelemetry(MovementEventType);

protected:
	virtual void onMovePlayerPacketNormal(const Vec3 &, const Vec2 &, float);

	// Begin Non-Virtual Functions
public:
	EnderChestContainer *getEnderChestContainer();
	Player(Level &, PacketSender &, GameType, const NetworkIdentifier &, unsigned char, mce::UUID, const std::string &, std::unique_ptr<Certificate>, const std::string &, const std::string &);
	bool isSurvival() const;
	bool canBeSeenOnMap() const;
	void startUsingItem(const ItemStack &, int);
	void stopUsingItem();
	void releaseUsingItem();
	void handleJumpEffects();
	void updateInventoryTransactions();
	bool canUseAbility(AbilitiesIndex) const;
	bool isInCreativeMode() const;
	float getDestroySpeed(const Block &) const;
	float getDestroyProgress(const Block &) const;
	bool canUseOperatorBlocks() const;
	bool canDestroy(const Block &) const;
	bool take(Actor &, int, int);
	void recheckSpawnPosition();
	const ItemStack &getSelectedItem() const;
	bool isHiddenFrom(Mob &) const;
	void setBedRespawnPosition(const BlockPos &);
	void setRespawnPosition(const BlockPos &, bool);
	void clearRespawnPosition();
	bool isInRaid() const;
	void updateTeleportDestPos();
	GameType getPlayerGameType() const;
	void eat(int, float);
	void causeFoodExhaustion(float);
	int getXpNeededForNextLevel() const;
	void setContainerManager(std::shared_ptr<IContainerManager>);
	void resetPlayerLevel();
	const ItemStack &getCurrentActiveShield() const;
	void setPlayerUIItem(PlayerUISlot, const ItemStack &);
	void updateTrackedBosses();
	void stopGliding();
	void setAgent(Agent *);
	Agent *getAgent() const;
	int getDirection() const;
	bool checkNeedAutoJump(float, float);
	void updateSkin(const SerializedSkin &, int);

private:
	void _ensureSafeSpawnPosition(Vec3 &);
	void _addLevels(int);
	bool _blockUsingShield(const ActorDamageSource &, float);
	void _sendShieldUpdatePacket(const ShieldItem *, const ItemStack &, const ItemStack &, ContainerID, int);
	void _registerElytraLoopSound();
	bool _findFallbackSpawnPosition(Vec3 &, std::vector<BlockSource, std::allocator<BlockSource>> *, unsigned int);
	void _handleCarriedItemInteractText();

protected:
	bool checkBed(BlockSource *, const Vec3 *);
	void _chooseSpawnArea();
	bool _validateSpawnPositionAvailability(const Vec3 &, BlockSource *, const Vec3 *) const;
	bool _isDangerousSpawn(BlockSource &, const AABB &) const;
	bool _chooseSpawnPositionWithinArea();
	bool checkAndfixSpawnPosition(Vec3 &, std::vector<BlockSource, std::allocator<BlockSource>> *, bool, bool, bool, bool) const;
	void registerAttributes();
	void _updateInteraction();

	// Begin Variables
	// public: static int const Player::UNTRACKED_INTERACTION_SLOT_COUNT;
	// public: static float const Player::DISTANCE_TO_TRANSFORM_EVENT;
	// public: static float const Player::PLAYER_DOWN_SWIM_SPEED;
	// public: static int const Player::GLIDE_STOP_DELAY;
	// public: static float const Player::PLAYER_SWIMMING_CAMERA_OFFSET;
	// public: static float const Player::PLAYER_UP_SWIM_SPEED;
	// public: static float const Player::PLAYER_SWIM_FLY_MULTI;
	// public: static class Vec3 const Player::INVALID_SPAWN_POS;
	// public: static class Attribute const Player::HUNGER;
	// public: static class Attribute const Player::SATURATION;
	// public: static class Attribute const Player::EXHAUSTION;
	// public: static class Attribute const Player::LEVEL;
	// public: static class Attribute const Player::EXPERIENCE;
};