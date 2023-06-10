#pragma once
#include <memory>

struct EntityId {
 private:
  uint32_t mRawId;

 public:
  EntityId(const EntityId &);
  EntityId(EntityId &&);
  EntityId(size_t);

 private:
  EntityId(void);

 public:
  EntityId &operator=(const EntityId &);
  EntityId &operator=(EntityId &&);
  bool operator==(const EntityId &) const;
  bool operator!=(const EntityId &) const;

 private:
  operator unsigned int &(void);
  operator unsigned int const(void) const;
};