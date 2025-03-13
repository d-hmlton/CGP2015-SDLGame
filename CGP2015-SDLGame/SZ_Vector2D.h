#pragma once

class SZ_Vector2D {
public:
	SZ_Vector2D();
	SZ_Vector2D(int eX, int eY);
	int x, y;

	float Magnitude();
};