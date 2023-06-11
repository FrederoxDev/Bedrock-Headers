#pragma once

#include <vector>

#include "Minecraft/Math/Vec.h"
#include "Minecraft/Util/AABB.h"

class Player;
class Mob;
class MerchantRecipeList;
class Actor;
class CompoundTag;
class DataLoadHelper;
class ActorInteraction;
class ItemStack;
class ContainerID;
class UpdateTradePacket;
class TradeTable;
class Trade;

class AABBShapeComponent {
 private:
  AABB mAABB;
  Vec2 mBBDim;

 public:
  const AABB &getAABB(void) const;
  const Vec2 &getAABBDim(void) const;

 protected:
  void setAABB(const AABB &);
  void setAABBDim(const Vec2 &);
};

class EconomyTradeableComponent {
 private:
  Player *mLastPlayerTradeName;
  int mUpdateMerchantTimer;
  bool mAddRecipeOnUpdate;
  int mRiches;
  Mob &mOwner;
  std::unique_ptr<MerchantRecipeList, std::default_delete<MerchantRecipeList> >
      mOffers;
  std::string mDisplayName;
  std::string mGeneratedTablePath;
  bool mConvertedFromVillagerV1;

 public:
  EconomyTradeableComponent(Actor &);
  void initFromDefinition(void);
  void reloadComponent(void);
  void newServerAiStep(void);
  void addAdditionalSaveData(CompoundTag &);
  void readAdditionalSaveData(const CompoundTag &, DataLoadHelper &);
  bool getInteraction(Player &, ActorInteraction &);
  void notifyTrade(int);
  void notifyTradeUpdated(ItemStack &, bool);
  MerchantRecipeList *getOffers(void);
  void setOffers(MerchantRecipeList *);
  void loadOffersFromTag(const CompoundTag *);
  void tryToTransferOldOffers(MerchantRecipeList *);
  void matchExpAndTier(void);
  void fixVillagerTierToMatchTradeList(MerchantRecipeList *);
  const std::string &getDisplayName(void) const;
  const std::string &loadDisplayName(void);
  bool isMaxLevel(void) const;
  int getTradeTier(void) const;
  int getMaxTradeTier(void) const;
  unsigned int getCurrentTradeExp(void) const;
  void setCurrentTradeExp(const int);
  std::vector<unsigned int, std::allocator<unsigned int> >
  getTradeExpRequirements(void) const;
  unsigned int getTradeExpForCurrentLevel(void) const;
  unsigned int getTradeExpToNextLevel(void) const;
  UpdateTradePacket createDataPacket(ContainerID);
  void setDataFromPacket(const UpdateTradePacket &);
  void resupplyTrades(void);
  bool hasSupplyRemaining(void) const;
  int getRiches(void) const;
  void setRiches(int);
  bool shouldPersistTrades(void) const;
  bool shouldConvertTrades(void) const;

 private:
  bool _generateTrades(void);
  TradeTable *_getTradeTable(void);
  void _setTradeTier(const int);
  void _setMaxTradeTier(const int);
  void _rearrangeTradeList(std::vector<Trade, std::allocator<Trade> > &,
                           size_t);
  bool _canLevelUp(void);
  int _getTradeTierFromCurrentExp(void);
  void _calculateDemandPrices(int);
};

class StateVectorComponent {
 private:
  Vec3 mPos;
  Vec3 mPosPrev;
  Vec3 mPosDelta;

 public:
  StateVectorComponent(void);
  const Vec3 &getPos(void) const;
  const Vec3 &getPosPrev(void) const;
  Vec3 &getPosDelta(void);
  const Vec3 &getPosDelta(void) const;

 protected:
  void _setPos(const Vec3 &);
  void _setPosPrev(const Vec3 &);
};