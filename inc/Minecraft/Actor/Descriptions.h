// File automatically generated from GenerateHeader.py
// https://github.com/FrederoxDev/Bedrock-GhidraScripts

#pragma once
#include <string>
#include <unordered_map>

#include "Minecraft/Util/StringHash.h"

namespace Json {
class Value;
};

struct DefintionDescription {
 public:
  virtual ~DefintionDescription(void);
  virtual const char *getJsonName(void) const;
};

struct Description {
 public:
  virtual const char *getJsonName(void) const;
  virtual ~Description(void);
  virtual void deserializeData(Json::Value &);
  virtual void serializeData(Json::Value &) const;

  // Begin Non-Virtual Functions
  Description *parseDescription(Json::Value &);
  static int getId(const std::string &);
  static void registerAttributes(void);
  static void registerProperties(void);
  static void registerTriggers(void);
  static void registerComponents(void);
  static void registerJsonName(const std::string &);
  static const std::string &getName(int);

 protected:
  bool startParsing(Json::Value &, Json::Value &, const char *);
};

struct ComponentDescription : public Description {};

struct IdentifierDescription : public DefintionDescription {
  std::string mId;

 public:
  IdentifierDescription(const char *);
  IdentifierDescription(const std::string &);
  virtual const char *getJsonName(void) const;
};

struct RuntimeIdentifierDescription : public DefintionDescription {
  std::string mRuntimeId;

 public:
  void parse(Json::Value &);
  virtual const char *getJsonName(void) const;
};

struct IsSpawnableDescription : public DefintionDescription {
  bool mIsSpawnable;

 public:
  void parse(Json::Value &);
  virtual const char *getJsonName(void) const;
};

struct IsSummonableDescription : public DefintionDescription {
  bool mIsSummonable;

 public:
  void parse(Json::Value &);
  virtual const char *getJsonName(void) const;
};

struct IsExperimentalDescription : public DefintionDescription {
  bool mIsExperimental;

 public:
  void parse(Json::Value &);
  virtual const char *getJsonName(void) const;
};

struct AnimationsDescription : public ComponentDescription {
  std::unordered_map<
      HashedString, HashedString, std::hash<HashedString>,
      std::equal_to<HashedString>,
      std::allocator<std::pair<HashedString const, HashedString> > >
      mActorAnimationMap;

 public:
  virtual void deserializeData(Json::Value &);
  virtual void serializeData(Json::Value &) const;
  virtual const char *getJsonName(void) const;
};

struct AnimationScriptsDescription : public ComponentDescription {
    std::vector<std::pair<HashedString, ExpressionNode>, std::allocator<std::pair<HashedString, ExpressionNode> > > mAnimateScript;
  public:
    virtual void deserializeData(Json::Value &);
    virtual void serializeData(Json::Value &) const;
    virtual const char * getJsonName(void) const;
};