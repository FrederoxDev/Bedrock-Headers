#pragma once
#include <memory>
#include <string>

namespace mce {
class UUID {
 public:
  static mce::UUID EMPTY;
  static size_t STRING_LENGTH;

 private:
  uint64_t Data[2];

 public:
  UUID(void);
  UUID(uint64_t, uint64_t);
  static mce::UUID fromString(const std::string &);
  static mce::UUID seedFromString(const std::string &);
  uint64_t getMostSignificantBits(void) const;
  uint64_t getLeastSignificantBits(void) const;
  std::string asString(void) const;
  bool operator<(const mce::UUID &) const;
  bool operator==(const mce::UUID &) const;
  bool operator!=(const mce::UUID &) const;
  size_t getHash(void) const;
  bool isEmpty(void) const;
};
};  // namespace mce