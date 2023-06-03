// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
#include "Minecraft/Entity/Player.h"

class PacketSender;
class IContainerManager;
class PlayerEventCoordinator;
class FrameUpdateContextBase;
class DataLoadHelper;
class Actor;
class Vec3;
class BlockPos;
class NetworkHandler;
class VariantParameterList;
class CompoundTag;
class ChunkSource;
class Packet;
class MoveInputHandler;
class MobEffectInstance;
class TextObjectRoot;
class ActorDamageSource;
class NetworkIdentifier;
class Level;
class ItemStack;
class InventoryTransaction;
struct ActorUniqueID;
struct Tick;
enum InputMode;
enum ActorEvent;
enum GameType;
enum ClientPlayMode;
enum CommandPermissionLevel;
enum ArmorSlot;
enum MovementEventType;

class ServerPlayer : public Player
{
private:
	NetworkHandler &mNetworkHandler;
	OnPlayerLoadedCallback mOnPlayerLoadedCallback;
	NetworkChunkPublisher mChunkPublisherView;
	InventoryMenu mInventoryMenu;
	ContainerID mContainerCounter;
	uint32_t mMaxChunkRadius;
	bool mLoading;
	bool mIsTeacher;
	bool mTeleportedThisTick;
	bool mLocalPlayerInitialized;
	Tick mPrevShieldBlockingTick;
	std::unique_ptr<CompoundTag, std::default_delete<CompoundTag>> mLostDataTag;
	uint32_t mClientViewRadius;
	uint32_t mClientRequestedRadius;
	int mRemainingStructureRefreshTicks;
	StructureFeatureType mCurrentStructureFeature;
	std::chrono::_V2::steady_clock::time_point mLastKnownSyncTime;
	std::chrono::_V2::steady_clock::time_point mLastKnownDesyncTime;
	float mCheatingStrikeScore;
	std::unordered_map<ActorUniqueID, ServerPlayer::NearbyActor, std::hash<ActorUniqueID>, std::equal_to<ActorUniqueID>, std::allocator<std::pair<ActorUniqueID const, ServerPlayer::NearbyActor>>> mNearbyActors;
	Unique<ServerMoveInputHandler> mMoveInputHandler;
	InputMode mCurrentInputMode;
	ClientPlayMode mPlayMode;
	PlayerMovementTelemetryData mMovementData;

public:
	virtual void initializeComponents(Actor::InitializationMethod, const VariantParameterList &);
	// ~ServerPlayer
	// ~ServerPlayer
	virtual void normalTick();
	virtual bool isValidTarget(Actor *) const;
	virtual void handleEntityEvent(ActorEvent, int);
	virtual void setArmor(ArmorSlot, const ItemStack &);
	virtual bool load(const CompoundTag &, DataLoadHelper &);
	virtual bool canChangeDimensions() const;
	virtual void changeDimension(AutomaticID<Dimension, int>, bool);
	virtual ActorUniqueID getControllingPlayer() const;
	virtual void checkFallDamage(float, bool);
	virtual void handleFallDistanceOnServer(float, bool);

protected:
	virtual void onEffectAdded(MobEffectInstance &);
	virtual void onEffectUpdated(const MobEffectInstance &);
	virtual void onEffectRemoved(MobEffectInstance &);

public:
	virtual void die(const ActorDamageSource &);
	virtual void knockback(Actor *, int, float, float, float, float, float);
	virtual void aiStep();
	virtual void hurtArmor(int);
	virtual void sendInventory(bool);
	virtual void prepareRegion(ChunkSource &);
	virtual void destroyRegion();
	virtual void suspendRegion();
	virtual void changeDimensionWithCredits(AutomaticID<Dimension, int>);
	virtual int tickWorld(const Tick &);
	virtual void frameUpdate(FrameUpdateContextBase &);
	virtual void checkMovementStats(const Vec3 &);
	virtual void setPermissions(CommandPermissionLevel);
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
	virtual void openCommandBlock(const BlockPos &);
	virtual void openCommandBlockMinecart(const ActorUniqueID &);
	virtual void openHorseInventory(const ActorUniqueID &);
	virtual void openTrading(const ActorUniqueID &, bool);
	// openNpcInteractScreen
	virtual void openInventory();
	virtual void openStructureEditor(const BlockPos &);
	virtual void openLabTable(const BlockPos &);
	virtual void openElementConstructor(const BlockPos &);
	virtual void openCompoundCreator(const BlockPos &);
	virtual void openMaterialReducer(const BlockPos &);
	virtual void displayTextObjectMessage(const TextObjectRoot &, const std::string &, const std::string &);
	// displayTextObjectWhisperMessage
	virtual void displayWhisperMessage(const std::string &, const std::string &, const std::string &, const std::string &);
	virtual void stopSleepInBed(bool, bool);
	virtual bool isHostingPlayer() const;
	virtual bool isLoading() const;
	virtual bool isPlayerInitialized() const;
	virtual void setPlayerGameType(GameType);
	virtual void setContainerData(IContainerManager &, int, int);
	virtual void slotChanged(IContainerManager &, int, const ItemStack &, const ItemStack &, bool);
	virtual void refreshContainer(IContainerManager &);
	virtual void deleteContainerManager();
	virtual bool isPositionRelevant(AutomaticID<Dimension, int>, const BlockPos &);
	virtual bool isEntityRelevant(const Actor &);
	virtual bool isTeacher() const;
	virtual void onSuspension();
	virtual void onLinkedSlotsChanged();
	virtual void sendInventoryTransaction(const InventoryTransaction &) const;
	// sendComplexInventoryTransaction
	virtual void sendNetworkPacket(Packet &) const;
	virtual PlayerEventCoordinator &getPlayerEventCoordinator();
	virtual MoveInputHandler *getMoveInputHandler();
	virtual InputMode getInputMode() const;
	virtual ClientPlayMode getPlayMode() const;
	virtual void reportMovementTelemetry(MovementEventType);

	// Begin Non-Virtual Functions
	ServerPlayer(Level&, PacketSender&, NetworkHandler&, ClientBlobCache::Server::ActiveTransfersManager&, GameType, const NetworkIdentifier&, unsigned char, std::function<void__cdecl(ServerPlayer&) const;
	void selectItem(const ItemStack&, const int&);
	void sendMobEffectPackets();
	unsigned int findClientChunkRadius(unsigned int) const;
	void setClientChunkRadius(unsigned int);
	void checkCheating(const Vec3&);
private:
	void _setContainerManager(std::shared_ptr<IContainerManager>);
	void _updateNearbyActors();
	void _scanForNearbyActors();
	void _removeNearbyEntities();

	// Begin Variables
};