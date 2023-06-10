#pragma once

template <typename Dimension, typename ID_TYPE>
class DimensionType {
 private:
  ID_TYPE runtimeID;

  static ID_TYPE _makeRuntimeID(void);

 public:
  AutomaticID(void);
  AutomaticID(const SELF &);
  SELF &operator=(const SELF &);
  bool operator==(const SELF &) const;
  bool operator!=(const SELF &) const;
  const ID_TYPE &value(void) const;

 private:
  typedef AutomaticID<NAMESPACE, ID_TYPE> SELF;
};