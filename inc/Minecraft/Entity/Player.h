// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
// class std::shared_ptr<IContainerManager>;
// class std::vector< ItemStack   ,std::allocator< ItemStack   > >;
class ShieldItem;
class EnderChestContainer;
class AutomaticID<Dimension,int>;
class PacketSender;
class SerializedSkin;
class BlockSource;
class DataLoadHelper;
class Item;
// class std::unique_ptr< BodyControl,std::default_delete< BodyControl> >;
class Container;
// class std::vector<BlockSource,std::allocator<BlockSource>>;
// class mce::UUID;
class Vec2;
class Vec3;
class Actor;
class BlockPos;
class BlockActor;
class VariantParameterList;
// class std::vector< ChunkPos,std::allocator< ChunkPos> >;
class CompoundTag;
class ChalkboardBlockActor;
class ChunkSource;
class Packet;
class Mob;
class Agent;
class TextObjectRoot;
// class std::string;
class ActorDamageSource;
class NetworkIdentifier;
class Block;
class EventPacket;
class Level;
class ItemStack;
class IMinecraftEventing;
// class std::unique_ptr< Packet,std::default_delete< Packet> >;
class AABB;
class AnimationComponent;
// struct std::unique_ptr< BodyControl,std::default_delete< BodyControl> >;
// struct std::unique_ptr<Certificate,std::default_delete<Certificate>>;
// struct std::string;
struct ActorUniqueID;
struct Tick;
// struct std::unique_ptr< Packet,std::default_delete< Packet> >;
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
// enum Actor::InitializationMethod;
enum ArmorSlot;
enum MovementEventType;
enum ActorLocation;
enum BedSleepingResult;


class Player : public Mob {
public:
	virtual void reloadHardcoded(Actor::InitializationMethod, const VariantParameterList&);
	virtual void initializeComponents(Actor::InitializationMethod, const VariantParameterList&);
	virtual ~Player();
	virtual void remove();
	virtual Vec3 getAttachPos(ActorLocation, float) const;
	virtual void move(const Vec3&);
	virtual void teleportTo(const Vec3&, bool, int, int);
	virtual std::unique_ptr< Packet,std::default_delete< Packet> > getAddPacket();
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
	virtual bool isDamageBlocked(const ActorDamageSource&) const;
	virtual bool isCreativeModeAllowed();
	virtual bool attack(Actor&);
	virtual void adjustDamageAmount(int&) const;
	virtual bool isJumping() const;
	virtual bool isInvulnerableTo(const ActorDamageSource&) const;
	virtual void actuallyHurt(int, const ActorDamageSource*, bool);
protected:
	virtual void onBounceStarted(const BlockPos&, const Block&);
public:
	virtual void feed(int);
	virtual void handleEntityEvent(ActorEvent, int);
	virtual void awardKillScore(Actor&, int);
	virtual void setArmor(ArmorSlot, const ItemStack&);
	virtual const ItemStack& getCarriedItem() const;
	virtual void setCarriedItem(const ItemStack&);
	virtual void setOffhandSlot(const ItemStack&);
	virtual const ItemStack& getEquippedTotem() const;
	virtual bool consumeTotem();
	virtual ActorType getEntityTypeId() const;
	virtual int getPortalCooldown() const;
	virtual int getPortalWaitTime() const;
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Actor&) const;
	virtual bool canBePulledIntoVehicle() const;
	virtual void sendMotionPacketIfNeeded();
	virtual void startSwimming();
	virtual void stopSwimming();
	virtual CommandPermissionLevel getCommandPermissionLevel() const;
	virtual AnimationComponent& getAnimationComponent();
	virtual void useItem(ItemStack&, ItemUseMethod, bool);
	virtual float getMapDecorationRotation() const;
	virtual bool isWorldBuilder();
	virtual bool isCreative() const;
	virtual bool isAdventure() const;
	virtual bool add(ItemStack&);
	virtual bool drop(const ItemStack&, bool);
	virtual void startSpinAttack();
	virtual void stopSpinAttack();
	virtual void die(const ActorDamageSource&);
protected:
	virtual bool _hurt(const ActorDamageSource&, int, bool, bool);
	virtual void readAdditionalSaveData(const CompoundTag&, DataLoadHelper&);
	virtual void addAdditionalSaveData(CompoundTag&);
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
	virtual const std::vector< ItemStack   ,std::allocator< ItemStack   > >* getAllHand() const;
	virtual const std::vector< ItemStack   ,std::allocator< ItemStack   > >* getAllEquipment() const;
	virtual void sendInventory(bool);
	virtual bool canExistWhenDisallowMob() const;
	virtual bool useNewAi() const;
private:
	virtual std::unique_ptr< BodyControl,std::default_delete< BodyControl> > initBodyControl();
public:
	virtual void jumpFromGround();
protected:
	virtual void updateAi();
public:
	virtual void dropEquipment(const ActorDamageSource&, int);
	virtual void dropEquipment();
	virtual void updateGliding();
	virtual void prepareRegion(ChunkSource&);
	virtual void destroyRegion();
	virtual void suspendRegion();
	virtual void _fireWillChangeDimension();
	virtual void _fireDimensionChanged();
	virtual void changeDimensionWithCredits(AutomaticID<Dimension,int>);
	virtual int tickWorld(const Tick&);
	// Unknown pure virtual
	virtual const std::vector< ChunkPos,std::allocator< ChunkPos> >& getTickingOffsets() const;
	virtual void moveView();
	virtual void moveSpawnView(const Vec3&);
	virtual void setName(const std::string&);
	virtual void checkMovementStats(const Vec3&);
	virtual StructureFeatureType getCurrentStructureFeature() const;
	virtual bool isAutoJumpEnabled() const;
	virtual void respawn();
	virtual void resetRot();
	virtual void resetPos(bool);
	virtual bool isInTrialMode();
	virtual bool hasResource(int);
	virtual void completeUsingItem();
	virtual void setPermissions(CommandPermissionLevel);
	virtual void startCrafting(const BlockPos&, bool);
	virtual void startStonecutting(const BlockPos&);
	virtual void startDestroying();
	virtual void stopDestroying();
	virtual void openContainer(const BlockPos&);
	virtual void openContainer(const ActorUniqueID&);
	virtual void openFurnace(const BlockPos&);
	virtual void openBlastFurnace(const BlockPos&);
	virtual void openSmoker(const BlockPos&);
	virtual void openEnchanter(const BlockPos&);
	virtual void openAnvil(const BlockPos&);
	virtual void openGrindstone(const BlockPos&);
	virtual void openBrewingStand(const BlockPos&);
	virtual void openHopper(const BlockPos&);
	virtual void openHopper(const ActorUniqueID&);
	virtual void openDispenser(const BlockPos&, bool);
	virtual void openBeacon(const BlockPos&);
	virtual void openPortfolio();
	virtual void openBook(int, bool, int, BlockActor*);
	virtual void openCommandBlock(const BlockPos&);
	virtual void openCommandBlockMinecart(const ActorUniqueID&);
	virtual void openHorseInventory(const ActorUniqueID&);
	virtual void openTrading(const ActorUniqueID&, bool);
	virtual bool canOpenContainerScreen();
	virtual void openChalkboard(ChalkboardBlockActor&, bool);
	// openNpcInteractScreen
	virtual void openInventory();
	virtual void openStructureEditor(const BlockPos&);
	virtual void openLabTable(const BlockPos&);
	virtual void openElementConstructor(const BlockPos&);
	virtual void openCompoundCreator(const BlockPos&);
	virtual void openMaterialReducer(const BlockPos&);
	virtual void openLoom(const BlockPos&);
	virtual void openStonecutter(const BlockPos&);
	virtual void openCartographyTable(const BlockPos&);
	virtual void displayChatMessage(const std::string&, const std::string&);
	virtual void displayClientMessage(const std::string&);
	virtual void displayTextObjectMessage(const TextObjectRoot&, const std::string&, const std::string&);
	// displayTextObjectWhisperMessage
	virtual void displayWhisperMessage(const std::string&, const std::string&, const std::string&, const std::string&);
	virtual BedSleepingResult startSleepInBed(const BlockPos&);
	virtual void stopSleepInBed(bool, bool);
	virtual bool canStartSleepInBed();
	virtual int getSleepTimer() const;
	virtual int getPreviousTickSleepTimer() const;
	virtual void openSign(const BlockPos&);
	virtual void playEmote(const std::string&, bool);
	virtual bool isLocalPlayer() const;
	virtual bool isHostingPlayer() const;
	virtual bool isLoading() const;
	virtual bool isPlayerInitialized() const;
	virtual void stopLoading();
	virtual void registerTrackedBoss(ActorUniqueID);
	virtual void unRegisterTrackedBoss(ActorUniqueID);
	virtual void setPlayerGameType(GameType);
	virtual void _crit(Actor&);
	virtual IMinecraftEventing* getEventing() const;
	virtual unsigned int getUserId() const;
	virtual void sendEventPacket(EventPacket&) const;
	virtual void addExperience(int);
	virtual void addLevels(int);
	// Unknown pure virtual
	// Unknown pure virtual
	virtual void inventoryChanged(Container&, int, const ItemStack&, const ItemStack&);
	// Unknown pure virtual
	virtual void deleteContainerManager();
	virtual void setFieldOfViewModifier(float);
	virtual bool isPositionRelevant(AutomaticID<Dimension,int>, const BlockPos&);
	virtual bool isEntityRelevant(const Actor&);
	// Unknown pure virtual
	virtual void onSuspension();
	virtual void onLinkedSlotsChanged();
	virtual void startCooldown(const Item*);
	virtual int getItemCooldownLeft(CooldownType) const;
	virtual bool isItemInCooldown(CooldownType) const;
	// Unknown pure virtual
	// Unknown pure virtual
	virtual void sendNetworkPacket(Packet&) const;
	// Unknown pure virtual
	// Unknown pure virtual
	// Unknown pure virtual
	// Unknown pure virtual
	virtual void reportMovementTelemetry(MovementEventType);
protected:
	virtual void onMovePlayerPacketNormal(const Vec3&, const Vec2&, float);

// Begin Non-Virtual Functions
public:
	EnderChestContainer* getEnderChestContainer();
	Player(Level&, PacketSender&, GameType, const NetworkIdentifier&, unsignedchar, mce::UUID, const std::string&, std::unique_ptr<Certificate,std::default_delete<Certificate>>, const std::string&, const std::string&);
	bool isSurvival() const;
	bool canBeSeenOnMap() const;
	void startUsingItem(const ItemStack&, int);
	void stopUsingItem();
	void releaseUsingItem();
	void handleJumpEffects();
	void updateInventoryTransactions();
	bool canUseAbility(AbilitiesIndex) const;
	bool isInCreativeMode() const;
	float getDestroySpeed(const Block&) const;
	float getDestroyProgress(const Block&) const;
	bool canUseOperatorBlocks() const;
	bool canDestroy(const Block&) const;
	bool take(Actor&, int, int);
	void recheckSpawnPosition();
	const ItemStack& getSelectedItem() const;
	bool isHiddenFrom(Mob&) const;
	void setBedRespawnPosition(const BlockPos&);
	void setRespawnPosition(const BlockPos&, bool);
	void clearRespawnPosition();
	bool isInRaid() const;
	void updateTeleportDestPos();
	GameType getPlayerGameType() const;
	void eat(int, float);
	void causeFoodExhaustion(float);
	int getXpNeededForNextLevel() const;
	void setContainerManager(std::shared_ptr<IContainerManager>);
	void resetPlayerLevel();
	const ItemStack& getCurrentActiveShield() const;
	void setPlayerUIItem(PlayerUISlot, const ItemStack&);
	void updateTrackedBosses();
	void stopGliding();
	void setAgent(Agent*);
	Agent* getAgent() const;
	int getDirection() const;
	bool checkNeedAutoJump(float, float);
	void updateSkin(const SerializedSkin&, int);
private:
	void _ensureSafeSpawnPosition(Vec3&);
	void _addLevels(int);
	bool _blockUsingShield(const ActorDamageSource&, float);
	void _sendShieldUpdatePacket(const ShieldItem*, const ItemStack&, const ItemStack&, ContainerID, int);
	void _registerElytraLoopSound();
	bool _findFallbackSpawnPosition(Vec3&, std::vector<BlockSource,std::allocator<BlockSource>>*, unsignedint);
	void _handleCarriedItemInteractText();
protected:
	bool checkBed(BlockSource*, const Vec3*);
	void _chooseSpawnArea();
	bool _validateSpawnPositionAvailability(const Vec3&, BlockSource*, const Vec3*) const;
	bool _isDangerousSpawn(BlockSource&, const AABB&) const;
	bool _chooseSpawnPositionWithinArea();
	bool checkAndfixSpawnPosition(Vec3&, std::vector<BlockSource,std::allocator<BlockSource>>*, bool, bool, bool, bool) const;
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