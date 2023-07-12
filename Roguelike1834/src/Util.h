#pragma once
#include <raylib.h>
class Util
{
public:
	static inline Rectangle MakeRectangle(int x, int y, int width, int height) {
		return Rectangle{ float(x), float(y), float(width), float(height) };
	}

	static inline Vector2 MakeVector2(int x, int y) {
		return Vector2{ float(x), float(y) };
	}
};

