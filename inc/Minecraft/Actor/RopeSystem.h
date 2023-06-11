#pragma once

#include <vector>
#include <set>

#include "Minecraft/Actor/ActorUniqueID.h"
#include "Minecraft/Math/Vec.h"
#include "Minecraft/Util/AABB.h"
#include "Minecraft/Memory/SharedPtr.h"
#include "Minecraft/Memory/Mutex.h"

class BlockSource;
class RopePointsRef;

struct RopeParams {
    float mNodeDist;
    float mNodeSize;
    float mGravity;
    float mSlack;
    float mMaxTension;
    float mVelDamping;
    float mRelaxation;
    float mFriction;
    Vec3 mStartPin;
    Vec3 mEndPin;
    size_t mIterations;
    size_t mDestroyDelay;
    int mFlags;
    float mLength;
    float mOriginalNodeDist;
  public:
    RopeParams(void);
    RopeParams(const Vec3 &, const Vec3 &, float);
    void leadInit(void);
};

struct RopePoint {
  private:
    Vec3 mOldPos;
    Vec3 mToNewPos;

  public:
    RopePoint(const Vec3 &);
    RopePoint(void);
    Vec3 getInterpolated(float) const;
    void update(const Vec3 &);
};

struct RopePoints {
  private:
    size_t mSize;
    std::vector<RopePoint, std::allocator<RopePoint> > mPoints;

  public:
    size_t size(void) const;
    void beginRope(void);
    void endRope(void);
    void pushBack(const Vec3 &);
    Vec3 getInterpolated(size_t, float) const;
    void freezeInterpolation(void);
    void reserve(size_t);
};

struct RopeNode {
    Vec3 mPos;
    Vec3 mPrevPos;
    char mFrictionAxis;
  public:
    RopeNode(void);
    RopeNode(const Vec3 &);
};

struct RopeWave {
    enum Direction {StartToEnd, EndToStart};
    Vec3 mForce;
    float mSpeed;
    float mDamping;
    size_t mCurNode;
    float mDistAlongNode;
    RopeWave::Direction mDir;
  public:
    RopeWave(const Vec3 &, float, RopeWave::Direction, float);
};

struct AABBContactPoint {
    int mNormalIndex;
    float mSignedPenetration;
    Vec3 mNormal;
};

struct RopeAABB {
    AABB mBB;
    bool mBlacklisted;
  public:
    RopeAABB(const AABB &, bool);
    RopeAABB(void);
    bool getContactPoint(const Vec3 &, float, AABBContactPoint &) const;
};

struct AABBBucket {
  public:
    AABB mBucketBounds;
  private:
    int mCachedTicks;
    std::vector<RopeAABB, std::allocator<RopeAABB> > mBBs;
    bool mDirty;
    bool mNeedsFinalize;

  public:
    AABBBucket(void);
    const RopeAABB & get(size_t) const;
    RopeAABB & get(size_t);
    size_t size(void) const;
    void add(const RopeAABB &);
    void add(const std::vector<AABB, std::allocator<AABB> > &);
    void clear(void);
    void remove(size_t);
    void markDirty(void);
    void clearDirty(void);
    bool isDirty(void);
    bool needsFinalize(void) const;
    void clearNeedsFinalize(void);
    void mergeAABBs(void);
};

struct AABBPred {
  public:
    bool operator()(const AABB &, const AABB &) const;
};

class RopeSystem {
  public:
    static const float sEpsilon;
    static bool sEnabled;
    static const float sBucketLength;
    bool mWaveApplied;
  private:
    RopePoints mQueuedRenderPoints;
    RopePoints mRenderPoints;
    std::vector<RopeNode, std::allocator<RopeNode> > mNodes;
    std::vector<AABBBucket, std::allocator<AABBBucket> > mColliderBuckets;
    std::vector<RopeWave, std::allocator<RopeWave> > mWaves;
    RopeParams mParams;
    std::set<AABB, AABBPred, std::allocator<AABB> > mBlacklistedColliders;
    Vec3 mPrevStartPin;
    Vec3 mPrevEndPin;
    size_t mCutNode;
    size_t mCutRenderNode;
    size_t mMinNodes;
    size_t mCutTicks;
    ActorUniqueID mEndPinEntity;
    std::atomic_flag mTicking;
    Bedrock::Threading::Mutex mRenderMutex;
    bool mAbandonCollision;
    Vec3 mStartPin;
    Vec3 mEndPin;
    size_t mToCutNode;

  public:
    void initialize(const RopeParams &);
    void _initializePins(const Vec3 &, const Vec3 &);
  private:
    void _initializePins(void);
  public:
    void updatePins(const Vec3 &, const Vec3 &);
    void queueTick(BlockSource &, std::shared_ptr<RopeSystem> &);
    RopePointsRef getPoints(void);
    void cutAtPercent(float);
    size_t getCutNode(void) const;
    bool isCut(void) const;
    bool isDestroyed(void) const;
    void getPins(Vec3 &, Vec3 &) const;
    void storeEndPinEntity(const ActorUniqueID &);
    const ActorUniqueID & getEndPinEntity(void) const;
    void addWave(RopeWave);
  private:
    void _resizeRope(void);
    void _stretchRope(void);
    void _tick(void);
    void _tickWaves(void);
    void _integrate(void);
    float _solveDistanceConstraints3(void);
    float _solveDistanceConstraints1(void);
    bool _cacheColliders(BlockSource &);
    void _prepareAABBBuckets(void);
    void _pruneBlacklist(void);
    float _solveCollisions(bool);
    void _solvePinConstraints(void);
    void _solveFrictionConstraints(void);
    void _updateRenderPoints(void);
    void _pushRange(size_t, size_t);
    float _solveDistanceConstraint(Vec3 &, Vec3 &, float);
    float _propagateDistanceConstraint(const Vec3 &, Vec3 &, float);
    float _solveDistanceConstraintBlock(Vec3 &, Vec3 &, Vec3 &, Vec3 &, float);
    float _solveStartBlocks(void);
    float _solveEndBlocks(void);
    float _solveCollision(RopeNode &, const RopeAABB &);
    void _applyFriction1D(RopeNode &, int);
    AABBBucket & _getBucket(unsigned char);
    void _finalizeBucket(AABBBucket &);
    bool _startNewBucket(size_t, float);
};