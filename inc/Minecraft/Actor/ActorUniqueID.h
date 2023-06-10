#pragma once
#include <memory>
#include "Minecraft/Util/UUID.h"

struct ActorUniqueID {
  int64_t rawID;
  static const ActorUniqueID INVALID_ID;

 public:
  ActorUniqueID(void);
  ActorUniqueID(int64_t);
  static ActorUniqueID fromUUID(const mce::UUID &);
  static ActorUniqueID fromClientId(uint64_t);
  size_t getHash(void) const;
  operator bool(void) const;
  operator long(void) const;
  bool operator==(const ActorUniqueID &) const;
  bool operator!=(const ActorUniqueID &) const;
  bool operator>(const ActorUniqueID &) const;
  bool operator<(const ActorUniqueID &) const;
  ActorUniqueID &operator++(void);
  bool isValid(void) const;
};