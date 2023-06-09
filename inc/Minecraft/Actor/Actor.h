// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <unordered_set>

#include "Minecraft/Actor/ActorCategory.h"
#include "Minecraft/Actor/ActorUniqueID.h"
#include "Minecraft/Util/Color.h"
#include "Minecraft/Util/StringHash.h"
#include "Minecraft/Math/Vec.h"
#include "Minecraft/Actor/ActorDefinitionIdentifier.h"
#include "Minecraft/Actor/Descriptions.h"
#include "Minecraft/Actor/Definitions.h"
#include "Minecraft/Dimension/AutomaticID.h"
#include "Minecraft/Entity/EntityId.h"
#include "Minecraft/Actor/ActorRuntimeID.h"
#include "Minecraft/NBT/CompoundTag.h"
#include "Minecraft/Actor/VariantParameterList.h"
#include "Minecraft/Molang/MolangVariableMap.h"
#include "Minecraft/Actor/Components.h"
#include "Minecraft/Actor/BaseAttributeMap.h"
#include "Minecraft/Actor/ActionQueue.h"
#include "Minecraft/Container/SimpleContainer.h"
#include "Minecraft/Actor/ActorTerrainInterlockData.h"
#include "Minecraft/Actor/RopeSystem.h"

class Packet;
class DistanceSortedActor;
class ListTag;
class Options;
class RenderParams;
class UIProfanityContext;
class Attribute;
class ActionEvent;
class BlockSource;
class MerchantRecipeList;
class DataLoadHelper;
class AttributeInstance;
class EntityRegistryOwned;
class BlockPos;
class VariantParameterList;
class ITickingArea;
class ActorInteraction;
class LootTable;
class Mob;
class Player;
class ActorDefinitionGroup;
class ItemActor;
class MobEffectInstance;
class ChangeDimensionPacket;
class Dimension;
class ActorDamageSource;
class MobEffect;
class Block;
class Level;
class ItemStack;
class AABB;
class AnimationComponent;
struct EquipmentTableDescription;
struct SeatDescription;
struct ActorLink;
enum InputMode;
enum ActorEvent;
enum ArmorTextureType;
enum ItemUseMethod;
enum ActorType;
enum MaterialType;
enum CommandPermissionLevel;
enum ArmorMaterialType;
enum PaletteColor;
enum ArmorSlot;
enum LevelSoundEvent;
enum ActorFlags;
enum ActorLocation;
class ActorDefinitionDiffList;
class MobEffectInstanceList;

enum class PortalAxis : int {
	Unknown, 
	X, 
	Z, 
	_count
};

class ActorDefinitionDescriptor {
  public:
    char filler0[56]; //std::unordered_set<Util::HashString, Util::HashString::HashFunc, std::equal_to<Util::HashString>, std::allocator<Util::HashString> > mComponentNames;
    IdentifierDescription mIdentifier;
    RuntimeIdentifierDescription mRuntimeIdentifier;
    IsSpawnableDescription mIsSpawnable;
    IsSummonableDescription mIsSummonable;
    IsExperimentalDescription mIsExperimental;
    AnimationsDescription mAnimationsDescription;
    AnimationScriptsDescription mAnimationScriptsDescription;
    char filler1[24]; // std::vector<GoalDefinition, std::allocator<GoalDefinition> > mGoalDefinitions;
    char filler2[24]; //std::vector<ActorDefinitionAttribute, std::allocator<ActorDefinitionAttribute> > mAttributes;
    std::unordered_map<std::string, DefinitionEvent, std::hash<std::string>, std::equal_to<std::string >, std::allocator<std::pair<std::string const, DefinitionEvent> > > mEventHandlers;
    char filler3[136]; //DefinitionInstanceGroup mComponentDefinitionGroup;
    Description *mAttack;
    Description *mMobEffects;
    Description *mAmbientSoundInterval;
    Description *mCanClimb;
    Description *mCanFly;
    Description *mCanPowerJump;
    Description *mCollisionBox;
    Description *mColor2;
    Description *mColor;
    Description *mDefaultLookAngle;
    Description *mDyeable;
    Description *mEquipmentTable;
    Description *mFamilyTypes;
    Description *mFireImmune;
    Description *mFloatsInLiquid;
    Description *mFlyingSpeed;
    Description *mFootSize;
    Description *mFrictionModifier;
    Description *mSurfaceOffset;
    Description *mIsBaby;
    Description *mIsCharged;
    Description *mIsChested;
    Description *mIsHiddenWhenInvisible;
    Description *mIsIgnited;
    Description *mIsIllagerCaptain;
    Description *mIsSaddled;
    Description *mIsShaking;
    Description *mIsSheared;
    Description *mIsStunned;
    Description *mIsStackable;
    Description *mIsTamed;
    Description *mItemControllable;
    Description *mLootTable;
    Description *mPushthrough;
    Description *mScale;
    Description *mSoundVolume;
    Description *mWalkAnimSpeedMultiplier;
    Description *mWantsJockey;
    Description *mWASDControlled;
    Description *mOnDeath;
    Description *mOnFriendlyAnger;
    Description *mOnHurtByPlayer;
    Description *mOnHurt;
    Description *mOnIgnite;
    Description *mOnStartLanding;
    Description *mOnStartTakeoff;
    Description *mOnTargetAcquired;
    Description *mOnTargetEscape;
    Description *mOnWakeWithOwner;
    Description *mAmphibiousMoveControl;
    Description *mAngry;
    Description *mBehavior;
    Description *mBreakBlocks;
    Description *mBreakDoorAnnotation;
    Description *mBucketable;
    Description *mCommandBlock;
    Description *mContainer;
    Description *mDespawn;
    Description *mDweller;
    Description *mGenericMoveControl;
    Description *mGlideMoveControl;
    Description *mHide;
    Description *mIllagerBeastBlocked;
    Description *mManagedWanderingTrader;
    Description *mMarkVariant;
    Description *mMoveControl;
    Description *mDolphinSwimControl;
    Description *mFlyControl;
    Description *mHopControl;
    Description *mHoverControl;
    Description *mSwimControl;
    Description *mNameable;
    Description *mWallClimberNavigation;
    Description *mFloatNavigation;
    Description *mFlyingNavigation;
    Description *mHoverNavigation;
    Description *mGenericNavigation;
    Description *mWaterboundNavigation;
    Description *mNavigation;
    Description *mPersistent;
    Description *mPreferredPath;
    Description *mProjectile;
    Description *mPushable;
    Description *mRaidTrigger;
    Description *mRailActivator;
    Description *mRideable;
    Description *mShooter;
    Description *mSittable;
    Description *mSkinID;
    Description *mSlimeMoveControl;
    Description *mSpawnEntity;
    Description *mStrength;
    Description *mTags;
    Description *mTameable;
    Description *mTrail;
    Description *mTrusting;
    Description *mTargetNearby;
    Description *mTeleport;
    Description *mTickWorld;
    Description *mTimer;
    Description *mTradeResupply;
    Description *mTrust;
    Description *mEconomyTradeable;
    Description *mTransformation;
    Description *mVariant;
    Description *mWaterMovement;
    Description *mDynamicJumpControl;
    Description *mJumpControl;
    Description *mOpenDoorAnnotation;
    Description *mNpc;
    Description *mTripodCamera;

    ActorDefinitionDescriptor & combine(const ActorDefinitionDescriptor &);
    ActorDefinitionDescriptor & subtract(const ActorDefinitionDescriptor &);
    bool contains(const ActorDefinitionDescriptor &) const;
    bool overlaps(const ActorDefinitionDescriptor &) const;
    bool empty(void) const;
    bool hasComponent(const Util::HashString &) const;
    void executeEvent(Actor &, const std::string &, const VariantParameterList &);
    bool executeTrigger(Actor &, const DefinitionTrigger &, const VariantParameterList &);
    void forceExecuteTrigger(Actor &, const DefinitionTrigger &, const VariantParameterList &);
    // const ExplodeDefinition * tryGetComponentDefinition<ExplodeDefinition>(void);
    // const BreedableDefinition * tryGetComponentDefinition<BreedableDefinition>(void);
    // const BribeableDefinition * tryGetComponentDefinition<BribeableDefinition>(void);
    // const ScaleByAgeDefinition * tryGetComponentDefinition<ScaleByAgeDefinition>(void);
    // const AddRiderDefinition * tryGetComponentDefinition<AddRiderDefinition>(void);
    // const LegacyTradeableDefinition * tryGetComponentDefinition<LegacyTradeableDefinition>(void);
    // const BalloonDefinition * tryGetComponentDefinition<BalloonDefinition>(void);
    // const AgeableDefinition * tryGetComponentDefinition<AgeableDefinition>(void);
    // const BreathableDefinition * tryGetComponentDefinition<BreathableDefinition>(void);
    // const DamageOverTimeDefinition * tryGetComponentDefinition<DamageOverTimeDefinition>(void);
    // const GeneticsDefinition * tryGetComponentDefinition<GeneticsDefinition>(void);
    // const HomeDefinition * tryGetComponentDefinition<HomeDefinition>(void);
    // const GrowsCropDefinition * tryGetComponentDefinition<GrowsCropDefinition>(void);
    // const InsomniaDefinition * tryGetComponentDefinition<InsomniaDefinition>(void);
    // const MountTameableDefinition * tryGetComponentDefinition<MountTameableDefinition>(void);
};

class Actor {
  public:
  enum class InitializationMethod : unsigned char {
    INVALID,
    LOADED,
    SPAWNED,
    BORN,
    TRANSFORMED,
    UPDATED,
    EVENT,
    LEGACY
  };

 private:
  char filler1[24]; // OwnerPtr<EntityId> mEntity;
  Actor::InitializationMethod mInitMethod;
  std::string mCustomInitEventName;
  VariantParameterList mInitParams;
  bool mForceInitMethodToSpawnOnReload;
  bool mRequiresReload;

 public:
  DimensionType mDimensionId;
  bool mAdded;
  ActorDefinitionGroup *mDefinitions;
  std::unique_ptr<ActorDefinitionDescriptor> mCurrentDescription;
  static const std::string RIDING_TAG;
  static const int TOTAL_AIR_SUPPLY;
  static const int INVULNERABLE_DURATION;
  static const float DEFAULT_AMBIENT_SOUND_INTERVAL;
  static const float DEFAULT_AMBIENT_SOUND_INTERVAL_RANGE;
  ActorUniqueID mUniqueID;
  std::unique_ptr<RopeSystem> mLeashRopeSystem;
  Vec2 mRot;
  Vec2 mRotPrev;
  float mSwimAmount;
  float mSwimPrev;
  ChunkPos mChunkPos;
  Vec3 mRenderPos;
  Vec2 mRenderRot;
  int mAmbientSoundTime;
  int mLastHurtByPlayerTime;
  ActorCategory mCategories;
  char filler2[32]; //SynchedActorData mEntityData;
  char filler3[80]; // std::unique_ptr<SpatialActorNetworkData> mNetworkData;
  Vec3 mSentDelta;
  float mScale;
  float mScalePrev;
  HashType64 mNameTagHash;
  bool mOnGround;
  bool mWasOnGround;
  bool mHorizontalCollision;
  bool mVerticalCollision;
  bool mCollision;
  const Block *mInsideBlock;
  BlockPos mInsideBlockPos;
  float mFallDistance;
  bool mIgnoreLighting;
  bool mFilterLighting;
  Color mTintColor;
  Color mTintColor2;
  float mStepSoundVolume;
  float mStepSoundPitch;
  AABB *mLastHitBB;
  std::vector<AABB, std::allocator<AABB>> mSubBBs;
  float mTerrainSurfaceOffset;
  float mHeightOffset;
  float mExplosionOffset;
  float mShadowOffset;
  float mMaxAutoStep;
  float mPushthrough;
  float mWalkDistPrev;
  float mWalkDist;
  float mMoveDist;
  int mNextStep;
  float mBlockMovementSlowdownMultiplier;
  bool mImmobile;
  bool mWasInWater;
  bool mHasEnteredWater;
  bool mHeadInWater;
  bool mIsWet;
  Vec2 mSlideOffset;
  Vec3 mHeadOffset;
  Vec3 mEyeOffset;
  Vec3 mBreathingOffset;
  Vec3 mMouthOffset;
  Vec3 mDropOffset;
  bool mFirstTick;
  int mTickCount;
  int mInvulnerableTime;
  int mLastHealth;
  bool mFallDamageImmune;
  bool mHurtMarked;
  bool mWasHurtLastFrame;
  bool mInvulnerable;
  bool mAlwaysFireImmune;
  int mOnFire;
  int mFlameTexFrameIndex;
  float mFlameFrameIncrementTime;
  bool mOnHotBlock;
  int mClientSideFireTransitionStartTick;
  bool mClientSideFireTransitionLatch;
  int mPortalCooldown;
  BlockPos mPortalBlockPos;
  PortalAxis mPortalEntranceAxis;
  int mInsidePortalTime;
  std::vector<ActorUniqueID, std::allocator<ActorUniqueID>> mRiderIDs;
  std::vector<ActorUniqueID, std::allocator<ActorUniqueID>> mRiderIDsToRemove;
  ActorUniqueID mRidingID;
  ActorUniqueID mRidingPrevID;
  ActorUniqueID mPushedByID;
  bool mInheritRotationWhenRiding;
  bool mRidersChanged;
  bool mBlocksBuilding;
  bool mUsesOneWayCollision;
  bool mForcedLoading;
  bool mPrevPosRotSetThisTick;
  bool mTeleportedThisTick;
  bool mForceSendMotionPacket;
  float mSoundVolume;
  int mShakeTime;
  float mWalkAnimSpeedMultiplier;
  float mWalkAnimSpeedO;
  float mWalkAnimSpeed;
  float mWalkAnimPos;
  ActorUniqueID mLegacyUniqueID;
  bool mHighlightedThisFrame;
  bool mInitialized;

 private:
  BlockSource *mRegion;
  Dimension *mDimension;
  Level *mLevel;
  HashedString mActorRendererId;

 protected:
  HashedString mActorRendererIdThatAnimationComponentWasInitializedWith;
  bool mChanged;
  bool mRemoved;
  bool mGlobal;
  bool mAutonomous;
  ActorType mActorType;
  ActorDefinitionIdentifier mActorIdentifier;
  std::unique_ptr<BaseAttributeMap> mAttributes;
  std::unique_ptr<EconomyTradeableComponent> mEconomyTradeableComponent;
  std::shared_ptr<AnimationComponent> mAnimationComponent;
  AABBShapeComponent mAABBComponent;
  StateVectorComponent mStateVectorComponent;
  ActorUniqueID mTargetId;
  bool mLootDropped;
  float mRestrictRadius;
  BlockPos mRestrictCenter;
  ActorUniqueID mInLovePartner;
  char filler4[24]; // MobEffectInstanceList mMobEffects;
  bool mEffectsDirty;
  bool mPersistingTrade;
  std::unique_ptr<CompoundTag> mPersistingTradeOffers;
  int mPersistingTradeRiches;
  ActorRuntimeID mRuntimeID;
  Color mHurtColor;
  bool mEnforceRiderRotationLimit;
  std::unique_ptr<ActorDefinitionDiffList> mDefinitionList;
  bool mHasLimitedLife;
  int mLimitedLifeTicks;
  int mForceVisibleTimerTicks;
  std::string mFilteredNameTag;
  bool mIsStuckItem;
  float mRidingExitDistance;
  bool mIsSafeToSleepNear;
  ActorTerrainInterlockData mTerrainInterlockData;
  SimpleContainer mArmor;
  float mArmorDropChance[4];
  SimpleContainer mHand;
  float mHandDropChance[2];
  bool mIsKnockedBackOnDeath;

 private:
  static const int DAMAGE_NEARBY_MOBS_DURATION;
  static const int LEASHED_ENTITY_SEARCH_RADIUS;
  std::vector<AABB, std::allocator<AABB>> mOnewayPhysicsBlocks;
  bool mStuckInCollider;
  float mLastPenetration;
  bool mCollidableMobNear;
  bool mCollidableMob;
  bool mChainedDamageEffects;
  int mDamageNearbyMobsTick;
  bool mWasInBubbleColumn;
  bool mWasInWallLastTick;
  int mTicksInWall;
  bool mIsExperimental;
  std::unique_ptr<ActionQueue> mActionQueue;
  MolangVariableMap mMolangVariables;
  CompoundTag mCachedComponentData;
  ActorUniqueID mFishingHookID;

 protected:
  virtual void reloadHardcoded(Actor::InitializationMethod,
                               const VariantParameterList &);
  virtual void reloadHardcodedClient(Actor::InitializationMethod,
                                     const VariantParameterList &);
  virtual void initializeComponents(Actor::InitializationMethod,
                                    const VariantParameterList &);
  virtual void reloadComponents(Actor::InitializationMethod,
                                const VariantParameterList &);

 public:
  virtual bool hasComponent(const Util::HashString &) const;
  virtual ~Actor();
  virtual void reset();
  virtual int getOnDeathExperience();
  virtual ActorType getOwnerEntityType();
  virtual void remove();
  virtual void setPos(const Vec3 &);
  virtual const Vec3 &getPos() const;
  virtual const Vec3 &getPosOld() const;
  virtual const Vec3 getPosExtrapolated(float) const;
  virtual Vec3 getAttachPos(ActorLocation, float) const;
  virtual Vec3 getFiringPos() const;
  virtual void setRot(const Vec2 &);
  virtual void move(const Vec3 &);
  virtual Vec3 getInterpolatedRidingPosition(float) const;
  virtual float getInterpolatedBodyRot(float) const;
  virtual float getInterpolatedHeadRot(float) const;
  virtual float getInterpolatedBodyYaw(float) const;
  virtual float getYawSpeedInDegreesPerSecond() const;
  virtual float getInterpolatedWalkAnimSpeed(float) const;
  virtual Vec3 getInterpolatedRidingOffset(float) const;
  virtual void checkBlockCollisions(const AABB &);
  virtual void checkBlockCollisions();
  virtual bool breaksFallingBlocks() const;
  virtual void blockedByShield(const ActorDamageSource &, Actor &);
  virtual void moveRelative(float, float, float, float);
  virtual void teleportTo(const Vec3 &, bool, int, int);
  virtual bool tryTeleportTo(const Vec3 &, bool, bool, int, int);
  virtual void chorusFruitTeleport(Vec3 &);
  virtual void lerpTo(const Vec3 &, const Vec2 &, int);
  virtual void lerpMotion(const Vec3 &);
  virtual std::unique_ptr<Packet> getAddPacket();
  virtual void normalTick();
  virtual void baseTick();
  virtual void rideTick();
  virtual void positionRider(Actor &, float);
  virtual float getRidingHeight();
  virtual bool startRiding(Actor &);
  virtual void addRider(Actor &);
  virtual void flagRiderToRemove(Actor &);
  virtual std::string getExitTip(const std::string &, InputMode) const;
  virtual bool intersects(const Vec3 &, const Vec3 &) const;
  virtual bool isFree(const Vec3 &, float);
  virtual bool isFree(const Vec3 &);
  virtual bool isInWall() const;
  virtual bool isInvisible() const;
  virtual bool canShowNameTag() const;
  virtual bool canExistInPeaceful() const;
  virtual void setNameTagVisible(bool);
  virtual const std::string &getNameTag() const;
  virtual unsigned __int64 getNameTagAsHash() const;
  virtual std::string getFormattedNameTag() const;
  virtual void filterFormattedNameTag(const UIProfanityContext &);
  virtual void setNameTag(const std::string &);
  virtual bool getAlwaysShowNameTag() const;
  virtual void setScoreTag(const std::string &);
  virtual const std::string &getScoreTag() const;
  virtual bool isInWater() const;
  virtual bool hasEnteredWater() const;
  virtual bool isImmersedInWater() const;
  virtual bool isInWaterOrRain() const;
  virtual bool isInLava() const;
  virtual bool isUnderLiquid(MaterialType) const;
  virtual bool isOverWater() const;
  virtual void makeStuckInBlock(float);
  virtual float getCameraOffset() const;
  virtual float getShadowHeightOffs();
  virtual float getShadowRadius() const;
  virtual Vec3 getHeadLookVector(float);
  virtual bool canSeeInvisible() const;
  virtual bool canSee(const Actor &) const;
  virtual bool canSee(const Vec3 &) const;
  virtual bool isSkyLit(float);
  virtual float getBrightness(float) const;
  virtual bool interactPreventDefault();
  virtual void playerTouch(Player &);
  virtual void onAboveBubbleColumn(bool);
  virtual void onInsideBubbleColumn(bool);
  virtual bool isImmobile() const;
  virtual bool isSilent();
  virtual bool isPickable();
  virtual bool isFishable() const;
  virtual bool isSleeping() const;
  virtual bool isShootable();
  virtual bool isSneaking() const;
  virtual void setSneaking(bool);
  virtual bool isBlocking() const;
  virtual bool isDamageBlocked(const ActorDamageSource &) const;
  virtual bool isAlive() const;
  virtual bool isOnFire() const;
  virtual bool isOnHotBlock() const;
  virtual bool isCreativeModeAllowed();
  virtual bool isSurfaceMob() const;
  virtual bool isTargetable() const;
  virtual bool canAttack(Actor *, bool) const;
  virtual void setTarget(Actor *);
  virtual Actor *findAttackTarget();
  virtual bool isValidTarget(Actor *) const;
  virtual bool attack(Actor &);
  virtual void performRangedAttack(Actor &, float);
  virtual void adjustDamageAmount(int &) const;
  virtual int getEquipmentCount() const;
  virtual void setOwner(ActorUniqueID);
  virtual void setSitting(bool);
  virtual void onTame();
  virtual void onFailedTame();
  virtual int getInventorySize() const;
  virtual int getEquipSlots() const;
  virtual int getChestSlots() const;
  virtual void setStanding(bool);
  virtual bool canPowerJump() const;
  virtual void setCanPowerJump(bool);
  virtual bool isJumping() const;
  virtual bool isEnchanted() const;
  virtual void rideJumped();
  virtual void rideLanded(const Vec3 &, const Vec3 &);
  virtual bool shouldRender() const;
  virtual bool isInvulnerableTo(const ActorDamageSource &) const;
  virtual void actuallyHurt(int, const ActorDamageSource *, bool);
  virtual void animateHurt();
  virtual bool doFireHurt(int);
  virtual void onLightningHit();
  virtual void onBounceStarted(const BlockPos &, const Block &);
  virtual void feed(int);
  virtual void handleEntityEvent(ActorEvent, int);
  virtual float getPickRadius();
  virtual ItemActor *spawnAtLocation(int, int);
  virtual ItemActor *spawnAtLocation(int, int, float);
  virtual ItemActor *spawnAtLocation(const Block &, int);
  virtual ItemActor *spawnAtLocation(const Block &, int, float);
  virtual ItemActor *spawnAtLocation(const ItemStack &, float);
  virtual void despawn();
  virtual void killed(Actor &);
  virtual void awardKillScore(Actor &, int);
  virtual void setArmor(ArmorSlot, const ItemStack &);
  virtual const ItemStack &getArmor(ArmorSlot) const;
  virtual ArmorMaterialType getArmorMaterialTypeInSlot(ArmorSlot) const;
  virtual ArmorTextureType getArmorMaterialTextureTypeInSlot(ArmorSlot) const;
  virtual float getArmorColorInSlot(ArmorSlot, int) const;
  virtual void setEquippedSlot(ArmorSlot, int, int);
  virtual void setEquippedSlot(ArmorSlot, const ItemStack &);
  virtual const ItemStack &getCarriedItem() const;
  virtual void setCarriedItem(const ItemStack &);
  virtual void setOffhandSlot(const ItemStack &);
  virtual const ItemStack &getEquippedTotem() const;
  virtual bool consumeTotem();
  virtual bool save(CompoundTag &);
  virtual void saveWithoutId(CompoundTag &);
  virtual bool load(const CompoundTag &, DataLoadHelper &);
  virtual void loadLinks(const CompoundTag&, std::vector<ActorLink>&, DataLoadHelper&);
  virtual ActorType getEntityTypeId() const;
  virtual const HashedString &queryEntityRenderer() const;
  virtual ActorUniqueID getSourceUniqueID() const;
  virtual void setOnFire(int);
  virtual AABB getHandleWaterAABB() const;
  virtual void handleInsidePortal(const BlockPos &);
  virtual int getPortalCooldown() const;
  virtual int getPortalWaitTime() const;
  virtual AutomaticID<Dimension, int> getDimensionId() const;
  virtual bool canChangeDimensions() const;
  virtual void changeDimension(AutomaticID<Dimension, int>, bool);
  virtual void changeDimension(const ChangeDimensionPacket &);
  virtual ActorUniqueID getControllingPlayer() const;
  virtual void checkFallDamage(float, bool);
  virtual void causeFallDamage(float);
  virtual void handleFallDistanceOnServer(float, bool);
  virtual void playSynchronizedSound(LevelSoundEvent, const Vec3 &,
                                     const Block &, bool);
  virtual void playSynchronizedSound(LevelSoundEvent, const Vec3 &, int, bool);
  virtual void onSynchedDataUpdate(int);
  virtual bool canAddRider(Actor &) const;
  virtual bool canBePulledIntoVehicle() const;
  virtual bool inCaravan() const;
  virtual bool isLeashableType();
  virtual void tickLeash();
  virtual void sendMotionPacketIfNeeded();
  virtual bool canSynchronizeNewEntity() const;
  virtual void stopRiding(bool, bool, bool);
  virtual void startSwimming();
  virtual void stopSwimming();
  virtual void buildDebugInfo(std::string &) const;
  virtual CommandPermissionLevel getCommandPermissionLevel() const;
  virtual AttributeInstance *getMutableAttribute(const Attribute &);
  virtual const AttributeInstance &getAttribute(const Attribute &) const;
  virtual int getDeathTime() const;
  virtual void heal(int);
  virtual bool isInvertedHealAndHarm() const;
  virtual bool canBeAffected(int) const;
  virtual bool canBeAffected(const MobEffectInstance &) const;
  virtual bool canBeAffectedByArrow(const MobEffectInstance &) const;
  virtual void onEffectAdded(MobEffectInstance &);
  virtual void onEffectUpdated(const MobEffectInstance &);
  virtual void onEffectRemoved(MobEffectInstance &);
  virtual AnimationComponent &getAnimationComponent();
  virtual void openContainerComponent(Player &);
  virtual void swing();
  virtual void useItem(ItemStack &, ItemUseMethod, bool);
  virtual bool hasOutputSignal(unsigned char) const;
  virtual int getOutputSignal() const;
  virtual void getDebugText(std::vector<std::string> &);
  virtual float getMapDecorationRotation() const;
  virtual float getRiderYRotation(const Actor &) const;
  virtual float getYHeadRot() const;
  virtual bool isWorldBuilder();
  virtual bool isCreative() const;
  virtual bool isAdventure() const;
  virtual bool add(ItemStack &);
  virtual bool drop(const ItemStack &, bool);
  virtual bool getInteraction(Player &, ActorInteraction &, const Vec3 &);
  virtual bool canDestroyBlock(const Block &) const;
  virtual void setAuxValue(int);
  virtual void setSize(float, float);
  virtual int getLifeSpan() const;
  virtual void onOrphan();
  virtual void wobble();
  virtual bool wasHurt();
  virtual void startSpinAttack();
  virtual void stopSpinAttack();
  virtual void setDamageNearbyMobs(bool);
  virtual void renderDebugServerState(const Options &);
  virtual void reloadLootTable();
  virtual void reloadLootTable(const EquipmentTableDescription *);
  virtual float getDeletionDelayTimeSeconds() const;
  virtual void kill();
  virtual void die(const ActorDamageSource &);
  virtual bool shouldTick() const;

 protected:
  virtual void updateEntitySpecificMolangVariables(RenderParams &);
  virtual bool canMakeStepSound() const;
  virtual void outOfWorld();
  virtual bool _hurt(const ActorDamageSource &, int, bool, bool);
  virtual void markHurt();
  virtual void readAdditionalSaveData(const CompoundTag &, DataLoadHelper &);
  virtual void addAdditionalSaveData(CompoundTag &);
  virtual void _playStepSound(const BlockPos &, const Block &);
  virtual void _playFlySound(const BlockPos &, const Block &);
  virtual bool _makeFlySound() const;
  virtual void checkInsideBlocks(float);
  virtual void pushOutOfBlocks(const Vec3 &);
  virtual bool updateWaterState();
  virtual void doWaterSplashEffect();
  virtual void spawnTrailBubbles();
  virtual void updateInsideBlock();
  virtual LootTable *getLootTable();
  virtual LootTable *getDefaultLootTable();
  virtual void _removeRider(const ActorUniqueID &, bool, bool);

 private:
  virtual void _onSizeUpdated();
  virtual void _doAutoAttackOnTouch(Actor &);

  // Begin Non-Virtual Functions
 public:
  Actor(ActorDefinitionGroup *, const ActorDefinitionIdentifier &);
  Actor(Level &);
  void initEntity(EntityRegistryOwned &);
  void reload();
  void sendActorDefinitionEventTriggered(const std::string &);
  void updateDescription();
  void setBaseDefinition(const ActorDefinitionIdentifier &, bool, bool);
  bool hasFamily(const Util::HashString &) const;
  bool hasTag(const std::string &) const;
  bool addTag(const std::string &);
  const ActorUniqueID &getUniqueID() const;
  bool isUnderWaterfall() const;
  bool canBeginOrContinueClimbingLadder(bool) const;
  int getVariant() const;
  void setVariant(int);
  int getMarkVariant() const;
  void setMarkVariant(int);
  int getSkinID() const;
  void setSkinID(int);
  Actor *getTarget() const;
  int calculateAttackDamage(Actor &);
  Mob *getOwner() const;
  Player *getPlayerOwner() const;
  const ActorUniqueID getOwnerId() const;
  void setPersistent();
  bool hasSubBBInLava() const;
  static void checkEntityOnewayCollision(BlockSource &, const BlockPos &);
  void testForCollidableMobs(BlockSource &, const AABB &,
                             std::vector<AABB, std::allocator<AABB>> &);
  bool moveChunks();
  void setPreviousPosRot(const Vec3 &, const Vec2 &);
  Vec3 getViewVector(float) const;
  bool tick(BlockSource &);
  std::vector<ActorLink, std::allocator<ActorLink>> getLinks() const;
  void updateBBFromDescription();
  void positionAllRiders();
  Actor *getRideRoot() const;
  bool _tryPlaceAt(const Vec3 &);
  void removeAllRiders(bool, bool);
  void setSeatDescription(const Vec3 &, const SeatDescription &);
  void teleportRidersTo(const Vec3 &, int, int);
  void moveTo(const Vec3 &, const Vec2 &);
  bool hurt(const ActorDamageSource &, int, bool, bool);
  void spawnTamingParticles(bool);
  void setCanClimb(bool);
  bool canCurrentlySwim() const;
  void setCanFly(bool);
  void setJumpDuration(int);
  int getControllingSeat();
  Vec3 _randomHeartPos();
  void spawnEatParticles(const ItemStack &, int);
  void spawnDeathParticles();
  void spawnDustParticles(int);
  void spawnBalloonPopParticles();
  void setActorRendererId(HashedString);
  void pickUpItem(ItemActor &, int);
  std::unique_ptr<ListTag> saveLinks() const;
  void saveEntityFlags(CompoundTag &);
  void loadEntityFlags(const CompoundTag &, DataLoadHelper &);
  bool getStatusFlag(ActorFlags) const;
  bool setStatusFlag(ActorFlags, bool);
  void setStrengthMax(int);
  void setStrength(int);
  int getStrength() const;
  void playSound(LevelSoundEvent, const Vec3 &, int);
  bool isInsideBorderBlock(float) const;
  bool isFireImmune() const;
  bool hasPlayerRider() const;
  bool isRider(const Actor &) const;
  int getRiderIndex(Actor &) const;
  bool pullInEntity(Actor &);
  bool isRiding() const;
  void setLeashHolder(ActorUniqueID);
  void dropLeash(bool, bool);
  void forEachLeashedActor(std::function<void(Actor *)>);
  void sendMotionToServer();
  bool isControlledByLocalInstance() const;
  void _sendDirtyActorData();
  void addEffect(const MobEffectInstance &);
  void removeEffect(int);
  void removeAllEffects();
  bool hasEffect(const MobEffect &) const;
  const MobEffectInstance *getEffect(const MobEffect &) const;
  void setInvisible(bool);
  void updateInvisibilityStatus();
  void removeEffectParticles();
  std::unique_ptr<CompoundTag> getPersistingTradeOffers();
  void savePersistingTrade(std::unique_ptr<CompoundTag>, int);
  bool hasTickingArea() const;
  ITickingArea *getTickingArea();
  void updateTickingData();
  void transferTickingArea(Dimension &);
  void setColor(PaletteColor);
  PaletteColor getColor() const;
  void moveBBs(const Vec3 &);
  bool isWithinRestriction(const BlockPos &) const;
  bool hasRestriction() const;
  void dropTowards(const ItemStack &, Vec3);
  void setInLove(Actor *);
  MerchantRecipeList *getTradeOffers();
  bool onLadder(bool) const;
  void setTradingPlayer(Player *);
  Player *getTradingPlayer() const;
  void pushBackActionEventToActionQueue(ActionEvent);
  void setLimitedLife(int);
  bool shouldOrphan(BlockSource &);
  void setStructuralIntegrity(int);
  int getStructuralIntegrity() const;
  void setHurtTime(int);
  void setHurtDir(int);
  void updateInBubbleColumnState();
  std::vector<DistanceSortedActor, std::allocator<DistanceSortedActor>>
  fetchNearbyActorsSorted(const Vec3 &, ActorType);

 private:
  void _updateOwnerChunk();
  void _sendLinkPacket(const ActorLink &) const;
  void _manageRiders(BlockSource &);
  void _spawnPukeParticles();
  void _spawnTreasureHuntingParticles();
  void _initializeLeashRopeSystem();
  void _tryPlantWitherRose();
  bool _countFood(int);
  void _serializeComponents(CompoundTag &);

 protected:
  void _playMovementSound(bool);
  BlockPos _getBlockOnPos();
  void _refreshAABB();
  void _setNetherPortalData(AutomaticID<Dimension, int>,
                            AutomaticID<Dimension, int>, int);
};