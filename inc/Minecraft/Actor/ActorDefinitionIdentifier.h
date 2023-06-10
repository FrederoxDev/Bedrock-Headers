#pragma once
#include <string>

#include "Minecraft/Actor/ActorType.h"
#include "Minecraft/Util/StringHash.h"

struct ActorDefinitionIdentifier {
 public:
  static const std::string NAMESPACE_SEPARATOR;
  static const std::string EVENT_BEGIN;
  static const std::string EVENT_END;

 private:
  std::string mNamespace;
  std::string mIdentifier;
  std::string mInitEvent;
  std::string mFullName;
  HashedString mCanonicalName;

 public:
  ActorDefinitionIdentifier(void);
  ActorDefinitionIdentifier(std::string, std::string, std::string);
  ActorDefinitionIdentifier(const std::string &);
  ActorDefinitionIdentifier(const char *);
  ActorDefinitionIdentifier(ActorType);
  ActorDefinitionIdentifier(const ActorDefinitionIdentifier &);
  ActorDefinitionIdentifier(ActorDefinitionIdentifier &&);
  ActorDefinitionIdentifier &operator=(const ActorDefinitionIdentifier &);
  bool operator==(const ActorDefinitionIdentifier &) const;
  bool isEmpty(void) const;
  void clear(void);
  void initialize(const std::string &);
  void initialize(const std::string &, const std::string &, const std::string &);
  void setIdentifier(const std::string &);
  void setInitEvent(const std::string &);
  const std::string &getNamespace(void) const;
  const std::string &getIdentifier(void) const;
  const std::string &getInitEvent(void) const;
  const std::string &getCanonicalName(void) const;
  const HashedString &getCanonicalHash(void) const;
  const std::string &getFullName(void) const;
  bool isVanilla(void) const;
  ActorType _getLegacyActorType(void) const;

 private:
  void _initialize(void);
  static void _extractIdentifier(const std::string &, ActorDefinitionIdentifier &);
};