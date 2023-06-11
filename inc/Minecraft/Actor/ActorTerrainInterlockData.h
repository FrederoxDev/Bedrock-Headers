#pragma once
#include <chrono>

class ActorTerrainInterlockData {
 public:
  enum class VisibilityState : unsigned char {
    InitialNotVisible,
    Visible,
    DelayedDestructionNotVisible
  };

 protected:
  ActorTerrainInterlockData::VisibilityState mRenderVisibilityState;
  std::chrono::time_point<
      std::chrono::system_clock,
      std::chrono::duration<long, std::ratio<1, 1000000000> > >
      mCreationTime;
  bool mHasBeenDelayedDeleted;

 public:
  ActorTerrainInterlockData(void);
  std::chrono::system_clock::time_point getCreationTime(void) const;
  ActorTerrainInterlockData::VisibilityState getRenderVisibilityState(
      void) const;
  void setRenderVisibilityState(ActorTerrainInterlockData::VisibilityState);
  void setCreationTime(void);
  void setHasBeenDelayedDeleted(void);
  bool getHasBeenDelayedDeleted(void) const;
};