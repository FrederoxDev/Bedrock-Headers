// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "gsl/string_span"
#include "Minecraft/Math/Vec.h"

class FilterTest;
class FilterInput;
struct FilterParamDefinition;
struct FilterInputs;
struct FilterContext;
class IWorldRegistriesProvider;

typedef std::shared_ptr<FilterGroup> Ptr;
typedef gsl::basic_string_span<const char> string_span;

namespace Json {
class Value;
}

enum class FilterSubject : short {
  Self,
  Other,
  Player,
  Target,
  Parent,
  Baby,
  Block,
  COUNT
};

enum class FilterOperator : short {
  Equal,
  NotEqual,
  GreaterThan,
  LessThan,
  GreaterThanOrEqual,
  LessThanOrEqual
};

class Actor;
class VariantParameterList;
class BlockSource;
class Dimension;
class Level;
class Biome;
class TagRegistry;
class Block;

struct FilterContext {
  const Actor *mHost;
  const Actor *mSubject;
  const VariantParameterList *mParams;
  const BlockSource *mRegion;
  const Dimension *mDimension;
  const Level *mLevel;
  const Biome *mBiome;
  BlockPos mPos;
  const Block *mBlock;
  const TagRegistry *mTagRegistry;

 public:
  FilterContext(void);
};

typedef std::array<FilterContext, 7> FilterContextSet;

class FilterTest {
 public:
  struct Definition {
    std::string mName;
    std::string mDescription;
    const FilterParamDefinition *mSubjectDefinition;
    const FilterParamDefinition *mDomainDefinition;
    const FilterParamDefinition *mOperatorDefinition;
    const FilterParamDefinition *mValueDefinition;
    std::function<std::shared_ptr<FilterTest>()> mFactory;

   public:
    Definition(const std::string &, const std::string &,
               const FilterParamDefinition *, const FilterParamDefinition *,
               const FilterParamDefinition *, const FilterParamDefinition *,
               std::function<std::shared_ptr<FilterTest>()>);
  };

 protected:
  FilterSubject mSubject;
  FilterOperator mOperator;

 public:
  virtual ~FilterTest(void);
  virtual bool setup(const FilterTest::Definition &, const FilterInputs &);
  virtual bool evaluate(const FilterContext &) const;
  virtual void finalizeParsedValue(IWorldRegistriesProvider &);
  FilterSubject getSubject(void) const;
  Json::Value serialize(void) const;
  virtual string_span getName(void) const;

 protected:
  virtual Json::Value _serializeDomain(void) const;
  virtual Json::Value _serializeValue(void) const;
  bool _testValuesWithOperator(bool, bool) const;
  bool _testValuesWithOperator(int, int) const;
  bool _testValuesWithOperator(float, float) const;
  bool _testValuesWithOperator(const std::string &, const std::string &) const;
};

class FilterGroup {
 public:
  enum CollectionType { AND, OR, NOT };

  struct Definition {
    std::string mName;
    std::string mDescription;
    const FilterParamDefinition *mSubjectDefinition;
    const FilterParamDefinition *mDomainDefinition;
    const FilterParamDefinition *mOperatorDefinition;
    const FilterParamDefinition *mValueDefinition;
    std::function<std::shared_ptr<FilterTest>()> mFactory;

   public:
    Definition(const std::string &, const std::string &,
               const FilterParamDefinition *, const FilterParamDefinition *,
               const FilterParamDefinition *, const FilterParamDefinition *,
               std::function<std::shared_ptr<FilterTest>()>);
  };

 protected:
  FilterGroup::CollectionType mCollectionType;
  std::vector<std::shared_ptr<FilterGroup>,
              std::allocator<std::shared_ptr<FilterGroup>>>
      mChildren;
  std::vector<std::shared_ptr<FilterTest>,
              std::allocator<std::shared_ptr<FilterTest>>>
      mMembers;

 public:
  ~FilterGroup();

 protected:
  virtual Ptr _createSubgroup(FilterGroup::CollectionType) const;
  virtual bool _setupContext(const FilterTest &, FilterContext &) const;
  virtual bool _handleUnknownMember(const std::string &, const Json::Value &);

 public:
  FilterGroup(void);
  FilterGroup(FilterGroup::CollectionType);
  bool parse(const Json::Value &);
  bool evaluate(FilterContextSet &) const;
  bool addFilterTest(const std::string &, const FilterInputs &);
  bool addFilterTest(const FilterTest::Definition &, const FilterInputs &);
  void serialize(Json::Value &) const;
  bool empty(void);
  const std::vector<std::shared_ptr<FilterTest>,
                    std::allocator<std::shared_ptr<FilterTest>>> &
  getMembers(void) const;
  const std::vector<std::shared_ptr<FilterGroup>,
                    std::allocator<std::shared_ptr<FilterGroup>>> &
  getChildren(void) const;

 protected:
  bool _parseObject(const std::string &, const Json::Value &);
  bool _parseMember(const std::string &, const Json::Value &);
  bool _parseTest(const Json::Value &);
  bool _parseFilterInputs(const Json::Value &, const FilterTest::Definition &,
                          FilterInputs &);
  bool _parseFilterParam(const std::string &, const std::string &,
                         const Json::Value &, const FilterParamDefinition &,
                         FilterInput &);
  bool _evaluateMember(const FilterTest &, FilterContextSet &) const;
};