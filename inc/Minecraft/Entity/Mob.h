// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
#include "Minecraft/Entity/Actor.h"

class Options;
class Mob;
class Player;
class ActorDefinitionGroup;
class RenderParams;
class DataLoadHelper;
class Vec2;
class ActorDamageSource;
class Vec3;
class Block;
class BlockPos;
class Level;
class VariantParameterList;
class ItemStack;
class CompoundTag;
class BodyControl;
struct ActorDefinitionIdentifier;
struct ActorUniqueID;
struct TextureUVCoordinateSet;
enum ActorEvent;
enum ArmorTextureType;
enum EquipmentSlot;
enum ArmorMaterialType;
enum ArmorSlot;
enum LevelSoundEvent;

class Mob : public Actor {
public:
	static const float PLAYER_SWIMMING_SURFACE_OFFSET;
	static const float GLIDING_FALL_RESET_DELTA;
	static const float SLOW_FALL_GRAVITY;
	static const float DEFAULT_GRAVITY;
	static const float LADDER_CLIMB_SPEED;
	static const float SCAFFOLDING_CLIMB_SPEED;
	static const int ABSORPTION_FACTOR_MAX;
	static const int ABSORPTION_FACTOR_MIN;
	static const int TOTAL_ROLL_STEPS;
	static const int REMOVE_RIDERS_DELAY;
	float mYBodyRot;
	float mYBodyRotO;
	float mYHeadRot;
	float mYHeadRotO;
	int mHurtTime;
	int mHurtDuration;
	float mHurtDir;
	int mAttackTime;
	float mOTilt;
	float mTilt;
	int mLookTime;
	float mFallTime;
	bool mFloatsInLiquid;
	int mJumpTicks;
	Vec3 mElytraRot;
	CompassSpriteCalculator mCompassSpriteCalc;
	ClockSpriteCalculator mClockSpriteCalc;
	float mXxa;
	float mYya;
	float mZza;
	float mYRotA;
	bool mHasMoveInput;
	float mAttackAnim;
	float mORun;
	float mRun;

protected:
	static const int MAX_INACTIVITY_TIMER;
	bool mSwinging;
	int mSwingTime;
	int mNoActionTime;
	int mNoJumpDelay;
	float mDefaultLookAngle;
	float mFrictionModifier;
	float mFlyingSpeed;
	float mSwimSpeedMultiplier;
	int mDeathTime;
	int mDeathScore;
	float mAnimStep;
	float mAnimStepO;
	float mLockedBodyYRot;
	float mRiderYRotLimit;
	MovementInterpolator mInterpolation;
	int mLastHurt;
	ActorDamageCause mLastHurtCause;
	int mDmgSpill;
	int mDmgPartial;
	bool mJumping;
	bool mJumpVelRedux;
	float mPlayerJumpPendingScale;
	bool mAllowStandSliding;
	Vec3 mJumpStartPos;
	float mSpeed;
	bool mSurfaceMob;
	bool mNaturallySpawned;
	bool mDead;
	Weak<VillageLegacy> mVillageLegacy;
	bool mWantsToBeJockey;
	int mAmbientPlayBackInterval;
	bool mSpawnedXP;
	int mRollCounter;

private:
	static const int SWING_DURATION;
	static const int PLAYER_HURT_EXPERIENCE_TIME;
	ActorUniqueID mLookingAtId;
	ActorUniqueID mLastHurtMobId;
	ActorUniqueID mLastHurtByMobId;
	ActorUniqueID mLastHurtByPlayerId;
	ActorUniqueID mCaravanHead;
	ActorUniqueID mCaravanTail;
	int mLastHurtMobTimestamp;
	int mLastHurtByMobTime;
	float mOAttackAnim;
	int mArrowCount;
	int mRemoveArrowTime;
	int mFallFlyTicks;
	bool mHasBoundOrigin;
	BlockPos mBoundOrigin;
	MobSpawnMethod mSpawnMethod;
	bool mCreateAiOnReload;
	ActorUniqueID mTargetCaptainId;

public:
	virtual void reloadHardcoded(Actor::InitializationMethod, const VariantParameterList &);
	virtual void reloadHardcodedClient(Actor::InitializationMethod, const VariantParameterList &);
	virtual void initializeComponents(Actor::InitializationMethod, const VariantParameterList &);
	virtual bool hasComponent(const Util::HashString &) const;
	virtual ~Mob();
	virtual float getInterpolatedBodyRot(float) const;
	virtual float getInterpolatedHeadRot(float) const;
	virtual float getInterpolatedBodyYaw(float) const;
	virtual float getYawSpeedInDegreesPerSecond() const;
	virtual void blockedByShield(const ActorDamageSource &, Actor &);
	virtual void teleportTo(const Vec3 &, bool, int, int);
	virtual void lerpTo(const Vec3 &, const Vec2 &, int);
	virtual void normalTick();
	virtual void baseTick();

protected:
	virtual void rideTick();

public:
	virtual bool startRiding(Actor &);
	virtual void addRider(Actor &);
	virtual void playerTouch(Player &);
	virtual bool isImmobile() const;
	virtual bool isPickable();
	virtual bool isSleeping() const;
	virtual bool isShootable();
	virtual bool isBlocking() const;
	virtual bool isAlive() const;
	virtual bool isSurfaceMob() const;
	virtual void setTarget(Actor *);
	virtual bool attack(Actor &);
	virtual bool canPowerJump() const;
	virtual bool isJumping() const;
	virtual void actuallyHurt(int, const ActorDamageSource *, bool);
	virtual void animateHurt();
	virtual bool doFireHurt(int);
	virtual void handleEntityEvent(ActorEvent, int);
	virtual ArmorMaterialType getArmorMaterialTypeInSlot(ArmorSlot) const;
	virtual ArmorTextureType getArmorMaterialTextureTypeInSlot(ArmorSlot) const;
	virtual float getArmorColorInSlot(ArmorSlot, int) const;
	virtual void setEquippedSlot(ArmorSlot, int, int);
	virtual void setEquippedSlot(ArmorSlot, const ItemStack &);
	virtual void setOnFire(int);

protected:
	virtual void causeFallDamage(float);

public:
	virtual bool canBePulledIntoVehicle() const;
	virtual bool inCaravan() const;
	virtual void stopRiding(bool, bool, bool);
	virtual void buildDebugInfo(std::string &) const;
	virtual int getDeathTime() const;
	virtual void swing();
	virtual float getYHeadRot() const;
	virtual void renderDebugServerState(const Options &);
	virtual void kill();
	virtual void die(const ActorDamageSource &);

protected:
	virtual void updateEntitySpecificMolangVariables(RenderParams &);
	virtual void outOfWorld();
	virtual bool _hurt(const ActorDamageSource &, int, bool, bool);
	virtual void readAdditionalSaveData(const CompoundTag &, DataLoadHelper &);
	virtual void addAdditionalSaveData(CompoundTag &);
	virtual void _playStepSound(const BlockPos &, const Block &);
	virtual void _removeRider(const ActorUniqueID &, bool, bool);
	virtual void _onSizeUpdated();

public:
	virtual void knockback(Actor *, int, float, float, float, float, float);
	virtual void resolveDeathLoot(int, const ActorDamageSource &);
	virtual void spawnAnim();
	virtual void setSleeping(bool);
	virtual bool isSprinting() const;
	virtual void setSprinting(bool);
	virtual void playAmbientSound();
	virtual LevelSoundEvent getAmbientSound();
	virtual int getAmbientSoundPostponeTicks();
	virtual const TextureUVCoordinateSet *getItemInHandIcon(const ItemStack &, int);
	virtual float getSpeed() const;
	virtual void setSpeed(float);
	virtual float getJumpPower() const;
	virtual bool hurtEffects(const ActorDamageSource &, int, bool, bool);
	virtual int getMeleeWeaponDamageBonus(Mob *);
	virtual int getMeleeKnockbackBonus();
	virtual void travel(float, float, float);
	virtual void applyFinalFriction(float, bool);
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushActors();
	virtual void lookAt(Actor *, float, float);
	virtual bool isLookingAtAnEntity();
	virtual bool checkSpawnRules(bool);
	virtual bool checkSpawnObstruction() const;
	virtual bool shouldDespawn() const;
	virtual float getAttackAnim(float);
	virtual int getItemUseDuration();
	virtual float getItemUseStartupProgress();
	virtual float getItemUseIntervalProgress();
	virtual int getItemuseIntervalAxis();
	virtual int getTimeAlongSwing();
	virtual void ate();
	virtual float getMaxHeadXRot();
	virtual Mob *getLastHurtByMob();
	virtual void setLastHurtByMob(Mob *);
	virtual Player *getLastHurtByPlayer();
	virtual void setLastHurtByPlayer(Player *);
	virtual Mob *getLastHurtMob();
	virtual void setLastHurtMob(Actor *);
	virtual bool isAlliedTo(Mob *);
	virtual bool doHurtTarget(Actor *);
	virtual bool canBeControlledByRider();
	virtual void leaveCaravan();
	virtual void joinCaravan(Mob *);
	virtual bool hasCaravanTail() const;
	virtual ActorUniqueID getCaravanHead() const;
	virtual int getArmorValue();
	virtual float getArmorCoverPercentage() const;
	virtual void hurtArmor(int);
	virtual void containerChanged(int);
	virtual void updateEquipment();
	virtual int clearEquipment();
	virtual const std::vector<ItemStack, std::allocator<ItemStack>> *getAllArmor() const;
	virtual std::vector<int, std::allocator<int>> getAllArmorID() const;
	virtual const std::vector<ItemStack, std::allocator<ItemStack>> *getAllHand() const;
	virtual const std::vector<ItemStack, std::allocator<ItemStack>> *getAllEquipment() const;
	virtual int getArmorTypeHash();
	virtual void sendInventory(bool);
	virtual void sendArmor();
	virtual int getDamageAfterMagicAbsorb(const ActorDamageSource &, int);
	virtual bool createAIGoals();
	virtual void onBorn(Actor &, Actor &);
	virtual bool setItemSlot(EquipmentSlot, const ItemStack &);
	virtual void goDownInWater();
	virtual void setTransitioningSitting(bool);
	virtual void attackAnimation(Actor *, float);
	virtual int getAttackTime();
	virtual float _getWalkTargetValue(const BlockPos &);
	virtual bool canExistWhenDisallowMob() const;
	virtual bool useNewAi() const;
	virtual void ascendLadder();
	virtual void ascendScaffolding();
	virtual void descendScaffolding();

protected:
	virtual std::unique_ptr<BodyControl> initBodyControl();
	virtual void jumpFromGround();
	virtual void updateAi();
	virtual void newServerAiStep();
	virtual void _serverAiMobStep();
	virtual int getDamageAfterEnchantReduction(const ActorDamageSource &, int);
	virtual int getDamageAfterArmorAbsorb(const ActorDamageSource &, int);
	virtual void dropEquipment(const ActorDamageSource &, int);
	virtual void dropEquipment();
	virtual void dropBags();
	virtual void dropContainer();
	virtual void tickDeath();
	virtual void _endJump();
	virtual void updateGliding();
	virtual bool _allowAscendingScaffolding() const;

	// Begin Non-Virtual Functions
public:
	Mob(ActorDefinitionGroup *, const ActorDefinitionIdentifier &);
	Mob(Level &);
	bool checkTotemDeathProtection(const ActorDamageSource &);
	void frostWalk();
	TravelType getTravelType();
	float calcMoveRelativeSpeed(Mob::TravelType);
	void _updateMobTravel();
	void setEatCounter(int);
	bool shouldApplyWaterGravity();
	Mob *getFirstCaravanHead();
	int getCaravanSize() const;
	void resetAttributes();
	void setIsPregnant(bool);

private:
	bool _initHardCodedComponents();
	bool _isHeadInWater();
	bool _tryApplyingLevitation(Vec3 &) const;
	void _verifyAttributes();

protected:
	void calculateAmbientSoundTime(int);
	std::unique_ptr<ListTag> saveOffhand() const;
	void _applyRidingRotationLimits();
	float getJumpMultiplier();
	JumpPreventionResult getJumpPrevention();
	void emitJumpPreventedEvent(const BlockPos &);
	void _doSprintParticleEffect();
	int getCurrentSwingDuration();
	void updateAttackAnim();
	void tickEffects();
	void tickBlockDamage();
	void registerAttributes();

	// Begin Variables
	// protected: static int const Mob::MAX_INACTIVITY_TIMER;
	// public: static int const Mob::ABSORPTION_FACTOR_MAX;
	// public: static int const Mob::ABSORPTION_FACTOR_MIN;
	// public: static float const Mob::PLAYER_SWIMMING_SURFACE_OFFSET;
	// public: static int const Mob::TOTAL_ROLL_STEPS;
};