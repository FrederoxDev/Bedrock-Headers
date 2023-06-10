#pragma once
#include <memory>

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

class ClassID {
 public:
  typedef uint64_t IDType;

 private:
  static ClassID::IDType getNextID(void);
};

class VariantParameterList {
  struct Parameter {
    ClassID::IDType type;
    void *data;
  };

 private:
  Parameter parameters[7];

 public:
  bool hasParameter(FilterSubject) const;
  ClassID::IDType getParameterType(FilterSubject) const;
  size_t getParameterCount(void) const;
  void clearParameter(FilterSubject);
  void clear(void);
};