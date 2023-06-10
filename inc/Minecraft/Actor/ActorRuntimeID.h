#pragma once
#include <memory>

class ActorRuntimeID {
 public:
  uint64_t rawID;

  ActorRuntimeID(void);
  ActorRuntimeID(uint64_t);
  size_t getHash(void) const;
  operator bool(void) const;
  operator unsigned long(void) const;
  bool operator==(const ActorRuntimeID &) const;
  bool operator!=(const ActorRuntimeID &) const;
  ActorRuntimeID &operator++(void);
};