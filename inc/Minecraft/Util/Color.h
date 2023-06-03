#pragma once

#include <array>
#include <string>

#define get_a(c) ((c & 0xFF000000) >> 24)
#define get_r(c) ((c & 0xFF0000) >> 16)
#define get_g(c) ((c & 0xFF00) >> 8)
#define get_b(c) (c & 0xFF)

class Color {
public:
	static const Color NIL;
	static const Color WHITE;

	float r;
	float g;
	float b;
	float a;

	Color() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
	Color(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {}

	static Color fromABGR(int col) {
		return from255Range((col) & 0xFF, (col >> 8) & 0xFF, (col >> 16) & 0xFF, (col >> 24) & 0xFF);
	}

	static Color fromARGB(int col) {
		return from255Range((col >> 16) & 0xFF, (col >> 8) & 0xFF, (col) & 0xFF, (col >> 24) & 0xFF);
	}

	static Color fromRGB(int col) {
		return from255Range((col >> 16) & 0xFF, (col >> 8) & 0xFF, (col) & 0xFF, 255);
	}

	int toARGB() const {
		return ((int)(255.0 * a) << 24) + ((int)(255.0 * r) << 16) + ((int)(255.0 * g) << 8) + (int)(255.0 * b);
	}

	Color operator*(float s) const {
		return { r * s, g * s, b * s, a * s };
	}
	Color operator*(const Color& c) const {
		return { r * c.r, g * c.g, b * c.b, a * c.a };
	}

	static Color average(const Color& colorA, const Color& colorB, float percentage) {
		float opposite = 1 - percentage;

		float averageR = (float)sqrt((colorA.r * colorA.r) * (opposite)+(colorB.r * colorB.r) * (percentage));
		float averageG = (float)sqrt((colorA.g * colorA.g) * (opposite)+(colorB.r * colorB.g) * (percentage));
		float averageB = (float)sqrt((colorA.b * colorA.b) * (opposite)+(colorB.r * colorB.b) * (percentage));
		float averageA = colorA.a * opposite + colorB.a * percentage;

		return { averageR, averageG, averageB, averageA };
	}


	template<typename T>
	static Color from255Range(T r, T g, T b, T a) {
		return { r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f };
	}

};

inline const Color Color::NIL{ 0.0f, 0.0f, 0.0f, 0.0f };
inline const Color Color::WHITE{ 1.0f, 1.0f, 1.0f, 1.0f };