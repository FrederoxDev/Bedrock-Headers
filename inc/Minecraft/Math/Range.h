#pragma once

class Random;
namespace Json {
class Value;
}

struct FloatRange {
  float rangeMin;
  float rangeMax;

 public:
  float getValue(Random &) const;
  bool parseJson(const Json::Value &, float, float);
};

struct IntRange {
  static const IntRange ZERO;
  int rangeMin;
  int rangeMax;

 public:
  IntRange(void);
  IntRange(int);
  IntRange(int, int);
  int getValue(Random &) const;
  bool isInRangeInclusive(int) const;
  bool isInRangeExclusive(int) const;
  bool parseJson(Json::Value, int, int);
};