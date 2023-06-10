#pragma once

template <typename NAMESPACE, typename ID_TYPE>
class AutomaticID {
 private:
  ID_TYPE runtimeID;

  static ID_TYPE _makeRuntimeID();

 public:
  AutomaticID();
  AutomaticID(const AutomaticID& other);
  AutomaticID& operator=(const AutomaticID& other);
  bool operator==(const AutomaticID& other) const;
  bool operator!=(const AutomaticID& other) const;
  const ID_TYPE& value() const;

 private:
  typedef AutomaticID<NAMESPACE, ID_TYPE> SELF;
};

class Dimension;
using DimensionType = AutomaticID<Dimension, int>;