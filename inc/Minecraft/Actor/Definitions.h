#pragma once
#include <set>
#include <string>

#include "Minecraft/Items/Item.h"
#include "Minecraft/Math/Range.h"

class EntityContext;
class ExplodeComponent;
class BreedableComponent;
class BribeableComponent;
class ScaleByAgeComponent;
class AddRiderComponent;
class LegacyTradeableComponent;
class AgeableComponent;
class BreathableComponent;
class DamageOverTimeComponent;
class GeneticsComponent;
class GrowsCropComponent;
class InsomniaComponent;
class MountTamingComponent;

namespace JsonUtil {
template <typename T>
class JsonSchemaRoot;
}

class DefinitionTrigger {
 public:
  std::string mType;
  std::string mTarget;
  ActorFilterGroup mFilter;

  bool canTrigger(const Actor &, const VariantParameterList &) const;
};

// Begin Definitions

class ExplodeDefinition {
 public:
  FloatRange mFuseLength;
  float mExplosionPower;
  float mMaxResistance;
  bool mIsFuseLit;
  bool mCausesFire;
  bool mBreaksBlocks;
  bool mFireAffectedByGriefing;
  bool mDestroyAffectedByGriefing;

  static void buildSchema(JsonUtil::JsonSchemaRoot<ExplodeDefinition> &);
  void initialize(EntityContext &, ExplodeComponent &) const;
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
};

struct BreedableType {
  ActorDefinitionIdentifier mMateType;
  ActorDefinitionIdentifier mBabyType;
  DefinitionTrigger mOnBred;
};

struct EnvironmentRequirement {
  std::set<Block const *, std::less<Block const *>,
           std::allocator<Block const *> >
      mBlockTypes;
  unsigned int mNumBlocksRequired;
  unsigned int mSearchRadius;
};

struct MutationFactorData {
  float mVariant;
  float mExtraVariant;
  float mColor;
};

struct DenySameParentsVariantData {
  float mChance;
  int mVariantRangeMin;
  int mVariantRangeMax;
};

class BreedableDefinition {
 public:
  bool mTame;
  bool mBlendAttributes;
  float mExtraChance;
  float mBreedCooldownTimeSeconds;
  bool mInheritTamed;
  bool mAllowSitting;
  std::vector<ItemDescriptor, std::allocator<ItemDescriptor> > mBreedItems;
  std::vector<EnvironmentRequirement, std::allocator<EnvironmentRequirement> >
      mEnvironmentRequirements;
  ActorFilterGroup mLoveFilter;
  std::vector<BreedableType, std::allocator<BreedableType> > mBreedTypes;
  MutationFactorData mMutationFactors;
  DenySameParentsVariantData mDenyParentsVariant;
  bool mCausesPregnancy;

  static void buildSchema(JsonUtil::JsonSchemaRoot<BreedableDefinition> &);
  void initialize(EntityContext &, BreedableComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
  void addBreedItemByName(const std::string &);
  void addEnvironmentRequirement(const EnvironmentRequirement &);
  void addBreedableType(const BreedableType &);

 private:
  void _parseBreedTypes(Json::Value);
  void _parseEnvironmentRequirements(Json::Value);
};

class BribeableDefinition {
 public:
  float mBribeCooldown;
  std::set<Item const *, std::less<Item const *>, std::allocator<Item const *> >
      mBribeItems;

  static void buildSchema(JsonUtil::JsonSchemaRoot<BribeableDefinition> &);
  void initialize(EntityContext &, BribeableComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
  void addBribeItemByName(const std::string &);
};

class ScaleByAgeDefinition {
 public:
  float mStartScale;
  float mEndScale;

  static void buildSchema(JsonUtil::JsonSchemaRoot<ScaleByAgeDefinition> &);
  void initialize(EntityContext &, ScaleByAgeComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
};

class AddRiderDefinition {
 public:
  ActorDefinitionIdentifier mEntityType;

  static void buildSchema(JsonUtil::JsonSchemaRoot<AddRiderDefinition> &);
  void initialize(EntityContext &, AddRiderComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
};

class LegacyTradeableDefinition {
 public:
  std::string mDisplayName;
  std::string mTradeTablePath;
  bool mUseNewTradeScreen;
  bool mPersistTrades;
  bool mConvertTradesEconomy;

  static void buildSchema(
      JsonUtil::JsonSchemaRoot<LegacyTradeableDefinition> &);
  void initialize(EntityContext &, LegacyTradeableComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
};

class BalloonDefinition {
 public:
  Vec3 mLiftForce;

  static void buildSchema(JsonUtil::JsonSchemaRoot<BalloonDefinition> &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
};

struct ActorDefinitionFeedItem {
  const Item *mItem;
  float mGrowth;
};

class AgeableDefinition {
 public:
  float mSecondsAsBaby;
  std::vector<ActorDefinitionFeedItem, std::allocator<ActorDefinitionFeedItem> >
      mFeedItems;
  std::vector<Item const *, std::allocator<Item const *> > mDropItems;
  DefinitionTrigger mOnGrowUp;

  static void buildSchema(JsonUtil::JsonSchemaRoot<AgeableDefinition> &);
  void initialize(EntityContext &, AgeableComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
  void addFeedItemByName(const std::string &);
  void addDropItemByName(const std::string &);
  bool canGrowUp(void) const;
  int getTicksAsBaby(void) const;
};

class BreathableDefinition {
 public:
  int mTotalSupply;
  int mSuffocateTime;
  float mInhaleTime;
  bool mBreathesAir;
  bool mBreathesWater;
  bool mBreathesLava;
  bool mBreathesSolids;
  bool mGeneratesBubbles;
  std::set<Block const *, std::less<Block const *>,
           std::allocator<Block const *> >
      mBreathableBlocks;
  std::set<Block const *, std::less<Block const *>,
           std::allocator<Block const *> >
      mNonBreathableBlocks;

  static void buildSchema(JsonUtil::JsonSchemaRoot<BreathableDefinition> &);
  void initialize(EntityContext &, BreathableComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
  void addBreathableBlockByName(const std::string &);
  void addNonBreathableBlockByName(const std::string &);
};

class DamageOverTimeDefinition {
 public:
  int mDamagePerHurt;
  float mTimeBetweenHurt;

  static void buildSchema(JsonUtil::JsonSchemaRoot<DamageOverTimeDefinition> &);
  void initialize(EntityContext &, DamageOverTimeComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
};

struct GeneticVariant {
  IntRange mainAllele;
  IntRange hiddenAllele;
  IntRange eitherAllele;
  IntRange bothAllele;
  DefinitionTrigger onBorn;
};

struct GeneDefinition {
  std::string mName;
  IntRange mAlleleRange;
  std::vector<GeneticVariant, std::allocator<GeneticVariant> > mGeneticVariants;

 public:
  void addGeneticVariant(const GeneticVariant &);
};

class GeneticsDefinition {
 public:
  float mMutationRate;
  std::vector<GeneDefinition, std::allocator<GeneDefinition> > mGeneDefinitions;

 private:
  static const float DEFAULT_MUTATION_RATE;

 public:
  static void buildSchema(JsonUtil::JsonSchemaRoot<GeneticsDefinition> &);
  void initialize(EntityContext &, GeneticsComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
  void addGeneDefinition(const GeneDefinition &);

 private:
  void _parseGenes(Json::Value &);
  void _parseGeneticVariants(Json::Value &, GeneDefinition &);
};

class HomeDefinition {
 public:
  static void buildSchema(JsonUtil::JsonSchemaRoot<HomeDefinition> &);
};

class GrowsCropDefinition {
 public:
  int mCharges;
  float mChance;

  static void buildSchema(JsonUtil::JsonSchemaRoot<GrowsCropDefinition> &);
  void initialize(EntityContext &, GrowsCropComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
};

class InsomniaDefinition {
 public:
  float mDaysUntilInsomnia;

  static void buildSchema(JsonUtil::JsonSchemaRoot<InsomniaDefinition> &);
  void initialize(EntityContext &, InsomniaComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
};

struct FeedItem {
  struct Effect {
    std::string descriptionId;
    int id;
    int duration;
    int amplifier;
    float chance;
  };

  const Item *mItem;
  int mValue;
  std::vector<FeedItem::Effect, std::allocator<FeedItem::Effect> > mEffects;

 public:
  void setItem(const std::string &);
  void addEffect(const FeedItem::Effect &);
};

class MountTameableDefinition {
 public:
  int mMinTemper;
  int mMaxTemper;
  int mAttemptTemperMod;
  std::string mFeedText;
  std::string mRideText;
  DefinitionTrigger mOnTame;
  std::vector<FeedItem, std::allocator<FeedItem> > mFeedItems;
  std::vector<Item const *, std::allocator<Item const *> > mAutoRejectItems;

  static void buildSchema(JsonUtil::JsonSchemaRoot<MountTameableDefinition> &);
  void initialize(EntityContext &, MountTamingComponent &);
  void deserializeData(Json::Value &);
  void serializeData(Json::Value &) const;
  void addAutoRejectItemByName(const std::string &);
};