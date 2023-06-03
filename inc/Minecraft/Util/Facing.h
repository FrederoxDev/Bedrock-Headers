#pragma once
#include <array>

class Facing {
public:
	static const unsigned char DOWN = 0;
	static const unsigned char UP = 1;
	static const unsigned char NORTH = 2;
	static const unsigned char SOUTH = 3;
	static const unsigned char WEST = 4;
	static const unsigned char EAST = 5;

	/*static const BlockPos DIRECTION[6];
	static const std::array<std::vector<FacingID>, 6> ALL_EXCEPT;
	static const int STEP_X[6];
	static const int STEP_Y[6];
	static const int STEP_Z[6];*/
};

//inline const std::array<std::vector<FacingID>, 6> Facing::ALL_EXCEPT = { {
//	{ 1, 2, 3, 4, 5 },
//	{ 0, 2, 3, 4, 5 },
//	{ 1, 0, 3, 4, 5 },
//	{ 1, 0, 2, 4, 5 },
//	{ 1, 0, 2, 3, 5 },
//	{ 1, 0, 2, 3, 4 }
//} };
//
//inline const int Facing::STEP_X[6] = { 0, 0, 0, 0, -1, 1 };
//inline const int Facing::STEP_Y[6] = { -1, 1, 0, 0, 0, 0 };
//inline const int Facing::STEP_Z[6] = { 0, 0, -1, 1, 0, 0 };
//
//inline const BlockPos Facing::DIRECTION[6] = {
//	{ STEP_X[0], STEP_Y[0], STEP_Z[0] },
//	{ STEP_X[1], STEP_Y[1], STEP_Z[1] },
//	{ STEP_X[2], STEP_Y[2], STEP_Z[2] },
//	{ STEP_X[3], STEP_Y[3], STEP_Z[3] },
//	{ STEP_X[4], STEP_Y[4], STEP_Z[4] },
//	{ STEP_X[5], STEP_Y[5], STEP_Z[5] }
//};