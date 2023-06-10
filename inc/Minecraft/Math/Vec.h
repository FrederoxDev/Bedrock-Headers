#pragma once
#include <sstream>

 class ChunkPos {
  public:
    static const ChunkPos INVALID;
    static const ChunkPos MIN;
    static const ChunkPos MAX;
    // union {
    //     int64_t packed;
    //     struct {...};
    // };

    static ChunkPos max(const ChunkPos &, const ChunkPos &);
    static ChunkPos min(const ChunkPos &, const ChunkPos &);
    ChunkPos(void);
    ChunkPos(int, int);
    ChunkPos(const BlockPos &);
    ChunkPos(const Vec3 &);
    size_t hashCode(void) const;
    bool operator==(const ChunkPos &) const;
    bool operator!=(const ChunkPos &) const;
    ChunkPos & operator=(const ChunkPos &);
    ChunkPos operator+(const ChunkPos &) const;
    ChunkPos operator+(int) const;
    ChunkPos operator-(const ChunkPos &) const;
    ChunkPos operator-(int) const;
    int distanceToSqr(const ChunkPos &) const;
    float distanceToSqr(const Actor &) const;
    ChunkPos north(void) const;
    ChunkPos south(void) const;
    ChunkPos east(void) const;
	ChunkPos west(void) const;
    bool isNeighbor(const ChunkPos &) const;
    int getMiddleBlockX(void) const;
    int getMiddleBlockZ(void) const;
    BlockPos getMiddleBlockPosition(int) const;
};

class BlockPos {
public:
	int x, y, z;

	BlockPos(int a) : x(a), y(a), z(a) {};
	BlockPos(int x, int y, int z) : x(x), y(y), z(z) { };
};

class Vec2 {
public:
	float x, y;

	Vec2() { x = y = 0.0; }
	Vec2(float x, float y) : x(x), y(y) { }
};

class Vec3 {
public:
	float x, y, z;

	Vec3(float s) {
		x = s;
		y = s;
		z = s;
	}

	Vec3() { x = y = z = 0.0; }
	Vec3(float x, float y, float z) : x(x), y(y), z(z) { }
	Vec3(BlockPos const& pos) : x(float(pos.x)), y(float(pos.y)), z(float(pos.z)) {}

	bool operator==(const Vec3& rhs) const {
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}
};